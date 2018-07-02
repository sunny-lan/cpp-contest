#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 310
#define MAXN 301

vector<int> adj[MAXN];
int color[MAXN];

int n;

int _dp[MAXN][1600];

int& dp(int i, int j) {
	return _dp[i][j + 800];
}

void f(int i) {
	dp(i, 0) = min(1, dp(i, 0));

	int d = color[i] == 1 ? 1 : -1;
	int children = adj[i].size();

	for (int child : adj[i])
		f(child);

	if (children == 0)
		dp(i, d) = 0;

	if (children == 1)
		for (int j = -n; j <= n; j++)
			dp(i, j + d) = min(dp(i, j + d), dp(adj[i][0], j));

	if (children == 2)
		for (int j = -n; j <= n; j++)
			for (int k = -n; k <= n; k++)
				dp(i, j + k + d) = min(dp(i, j + k + d), dp(adj[i][0], j) + dp(adj[i][1], k));
}

int main() {
	int d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int id, c;
		cin >> id;
		cin >> color[id] >> c;
		for (int j = 0; j < c; j++)
		{
			int neigh;
			cin >> neigh;
			adj[id].push_back(neigh);
		}
		for (int j = -n; j <= n; j++)
			dp(i, j) = INF;
	}

	f(0);

	int res = dp(0, d);
	if (res >= INF)
		cout << -1 << endl;
	else
		cout << res << endl;
}