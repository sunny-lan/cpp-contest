#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1001
#define INF(a) (a==-1?INT_MAX:a)
#define MIN(a,b) INF(a)<INF(b)?a:b

vector<int> adj[MAXN];

int visited[MAXN];

int dp[MAXN + 1][MAXN + 1];//[curr][num in g1]
pair<int, int> src[MAXN + 1][MAXN + 1];
int out[MAXN + 1][MAXN + 1];

int cnt = 0;
vector<int> groupA[MAXN];
vector<int> groupB[MAXN];
int gAF[MAXN];
int gBF[MAXN];

int res[MAXN];

int cmp(int idx) {
	if (gAF[idx] < gBF[idx])
		return 1;
	return 2;
}

int main() {
	memset(dp, -1, sizeof dp);
	memset(gAF, -1, sizeof gAF);
	memset(gBF, -1, sizeof gBF);

	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int s, t; scan(s); scan(t);
		s--, t--;
		adj[s].push_back(t);
		adj[t].push_back(s);
	}

	dp[0][0] = 0;

	int pre = 0;
	int lastpre = 0;
	for (int i = 0; i < n; i++)
		if (visited[i] == 0) {
			queue<pair<int, int>> q;
			q.push({ i, 1 });
			int a = 0, b = 0;
			while (!q.empty()) {
				auto curr = q.front(); q.pop();
				if (visited[curr.first] != 0) {
					if (visited[curr.first] != curr.second) {
						cout << -1 << endl;
						return 0;
					}
					continue;
				}
				if (curr.second == 1) {
					groupA[cnt].push_back(curr.first);
					gAF[cnt] = MIN(gAF[cnt], curr.first);
					a++;
				}
				else {
					groupB[cnt].push_back(curr.first);
					gBF[cnt] = MIN(gBF[cnt], curr.first);
					b++;
				}
				visited[curr.first] = curr.second;

				pre++;
				for (int neigh : adj[curr.first])
					q.push({ neigh, curr.second == 1 ? 2 : 1 });
			}
			int correct = cmp(cnt);
			cout << "Curr step " << cnt << ", correct color " << correct << endl;
			for (int j = 0; j <= pre; j++) if (dp[cnt][j] != -1) {
				cout << "  Testing g1=" << j << endl;
				//a->g1
				int g1 = j;
				int g2 = lastpre - g1;
				g1 += a;
				g2 += b;
				int alt = abs(g1 - g2);
				cout << "    If A->G1 then G1=" << g1 << ", G2=" << g2 << ", diff=" << alt << endl;
				cout << "    Testing against curr optimal val, " << dp[cnt + 1][g1] << endl;
				if (alt < INF(dp[cnt + 1][g1])) {
					cout << "      Strictly less, setting new optimal val at -> ["<<cnt+1<<"]["<<g1<<"]" << endl;
					dp[cnt + 1][g1] = alt;
					src[cnt + 1][g1] = { cnt, j };
					out[cnt + 1][g1] = 1;
				}
				else if (alt == INF(dp[cnt + 1][g1])) {
					cout << "      Equal to optimal value, testing for lexicographically least" << endl;
					cout << "      Old selection was " << out[cnt + 1][g1] << ", new one will be 1" << endl;
					if (correct == 1 && out[cnt + 1][g1] == 2) {
						cout << "       Better lexicographic solution found -> [" << cnt + 1 << "][" << g1 << "]" << endl;
						dp[cnt + 1][g1] = alt;
						src[cnt + 1][g1] = { cnt, j };
						out[cnt + 1][g1] = 1;
					}
				}

				//b->g1
				g1 = j;
				g2 = lastpre - g1;
				g1 += b;
				g2 += a;
				alt = abs(g1 - g2);
				cout << "    If B->G1 then G1=" << g1 << ", G2=" << g2 << ", diff=" << alt << endl;
				cout << "    Testing against curr optimal val, " << dp[cnt + 1][g1] << endl;
				if (alt < INF(dp[cnt + 1][g1])) {
					cout << "      Strictly less, setting new optimal val -> [" << cnt + 1 << "][" << g1 << "]" << endl;
					dp[cnt + 1][g1] = alt;
					src[cnt + 1][g1] = { cnt, j };
					out[cnt + 1][g1] = 2;
				}
				else if (alt == INF(dp[cnt + 1][g1])) {
					cout << "      Equal to optimal value, testing for lexicographically least" << endl;
					cout << "      Old selection was " << out[cnt + 1][g1] << ", new one will be 2" << endl;
					if (correct == 2 && out[cnt + 1][g1] == 1) {
						cout << "       Better lexicographic solution found -> [" << cnt + 1 << "][" << g1 << "]" << endl;
						dp[cnt + 1][g1] = alt;
						src[cnt + 1][g1] = { cnt, j };
						out[cnt + 1][g1] = 2;
					}
				}
			}
			cnt++;
			lastpre = pre;
		}

	string best;
	int mini = -1;
	for (int i = 0; i <= n; i++) if (dp[cnt][i] != -1) {
		if (INF(dp[cnt][i]) <= INF(mini)) {

			pair<int, int> curr = { cnt, i };
			while (curr.first > 0) {
				int stuff = out[curr.first][curr.second];
				for (int ga : groupA[curr.first - 1]) {
					res[ga] = stuff;
				}
				for (int gb : groupB[curr.first - 1]) {
					res[gb] = stuff == 1 ? 2 : 1;
				}
				curr = src[curr.first][curr.second];
			}
			string tmp = "";
			for (int i = 0; i < n; i++)
				tmp += res[i] == 1 ? '1' : '2';
			if (INF(dp[cnt][i]) < INF(mini))
				best = string(tmp);
			else if (tmp < best)
				best = string(tmp);

			mini = dp[cnt][i];
		}
	}

	cout << best << endl;

	cin >> n;
}