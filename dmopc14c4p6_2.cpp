#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

#define MAXN 500000

vector<int> adj[MAXN];

unordered_map<int, int> dp[MAXN];

int f(int i, int j) {
	if (dp[i].find(j) != dp[i].end())
		return dp[i][j];

	int res = 0;
	for (int neigh : adj[i])
		if (neigh != j)
			res = max(res, f(neigh, i));

	dp[i][j] = ++res;

	return res;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u , &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		cout << f(i, -1) << endl;
}