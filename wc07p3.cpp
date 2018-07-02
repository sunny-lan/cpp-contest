#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 15

int n;
int adj[MAXN][MAXN];
int dp[MAXN][1 << MAXN];

int f(int i, int j) {
	int res = dp[i][j];
	if (res != -1)
		return res;

	if (i == 0)
		res = 1;
	else {
		res = 0;
		if (!((j >> i) & 1)) {
			int mask = j | (1 << i);
			for (int neigh = 0; neigh < n; neigh++) {
				if (adj[i][neigh]) {
					int alt = f(neigh, mask);
					if (alt != -1) {
						res += alt;
					}
				}
			}
		}
		if (res == 0)
			res = -1;
	}

	dp[i][j] = res;
	return res;
}

int main() {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> adj[j][i];
			}
		}
	}
	cout << f(n - 1, 0) % 13371337 << endl;
	cin >> n;
}