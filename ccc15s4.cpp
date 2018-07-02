#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
using namespace std;

#define memeset memset
#define INF(a) (a==-1?INT_MAX:a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 2000
#define MAXK 200

vector<pair<int, pii>> adj[MAXN];
int dp[MAXN][MAXK+1];
bool inq[MAXN];

int main() {
	memeset(dp, -1, sizeof dp);

	int k, n, m; scan(k); scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b, t, h; scan(a); scan(b); scan(t); scan(h);
		a--, b--;
		adj[a].push_back({ b,{t,h} });
		adj[b].push_back({ a,{t,h} });
	}

	int a, b; scan(a); scan(b);
	a--, b--;

	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0,a });
	dp[a][0] = 0;
	while (!q.empty()) {
		int i = q.top().second;
		q.pop();
		inq[i] = false;
		for (auto neigh : adj[i]) {
			int j = neigh.first;
			pii costs = neigh.second;
			for (int h = 0; h + costs.second <= k; h++) if(dp[i][h]!=-1){
				int alt = dp[i][h]+ costs.first;
				if (alt < INF(dp[j][h + costs.second])) {
					dp[j][h + costs.second] = alt;
					if (!inq[j]) {
						inq[j] = true;
						q.push({ alt, j });
					}
				}
			}
		}
	}

	int mini = -1;
	for (int i = 0; i < k; i++)
		if (INF(dp[b][i]) < INF(mini))
			mini = dp[b][i];
	cout << mini << endl;
}