#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF(a) (a==-1?INT_MAX:a)

#define MAXN 1600
#define MAXS 3601

typedef pair<int, int> pii;

vector<pair<int, pii>> adj[MAXN];

int dp[MAXN][MAXS];
bool visited[MAXN];
bool inq[MAXN];

int main() {
	memset(dp, -1, sizeof dp);

	int s, n, e; scan(s); scan(n); scan(e);
	for (int i = 0; i < e; i++) {
		int s, t, d, u; scan(s); scan(t); scan(d); scan(u);
		adj[s].push_back({ t, {d, u ? d : 0} });
		adj[t].push_back({ s, {d, u ? d : 0} });
	}

	dp[0][0] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		pii curr = q.top(); q.pop();
		int node = curr.second;
		inq[node] = false; //just popped it off
		for (auto neigh : adj[node]) {
			pii costs = neigh.second;
 			for (int i = 0; i <= s; i++) if (dp[node][i] != -1) {
				if (costs.second + i > s)
					break;

				int alt = costs.first + dp[node][i];
				if (alt < INF(dp[neigh.first][costs.second + i])) {
					dp[neigh.first][costs.second + i] = alt;
					if (!inq[neigh.first]) {
						inq[neigh.first] = true;
						q.push({alt, neigh.first});
					}
				}
			}
		}
	}

	int mini = INT_MAX;
	for (int i = 0; i <= s; i++)
		mini = min(mini, INF(dp[n - 1][i]));
	if (mini == INT_MAX)
		mini = -1;
	cout << mini << endl;
	cin >> mini;
}