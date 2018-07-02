#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1000001

int degrees[MAXN];
long double dp[MAXN];

int main() {
	int n,m;
	cin >> n>>m;
	vector<vector<int>> adj(n);
	for (int x = 0; x < m; x++) {
		int i, j;
		cin >> i >> j;
		i--, j--;
		adj[i].push_back(j);
		degrees[i]++;
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		long double prob = dp[i] / adj[i].size();
		for (int neight : adj[i]) {
			dp[neight] += prob;
		}
		if (degrees[i] == 0)
			printf("%.9Lg\n", dp[i]);
	}

	//cin >> n;


	return 0;
}