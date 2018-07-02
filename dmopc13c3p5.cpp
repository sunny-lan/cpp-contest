#include <iostream>
#include <algorithm>

using namespace std;

#define MAXR 151
#define MAXU 101
#define MAXM 301

int m, u, r;

int dp[MAXR][MAXU][MAXM];
int v[MAXR], t[MAXR], f[MAXR];

int main() {
	cin >> m >> u >> r;
	for (int i = 0; i < r; i++)
		cin >> v[i] >> t[i] >> f[i];

	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;

	int maxi = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j <= u; j++) {
			for (int k = 0; k <= m; k++) {
				if (dp[i][j][k] == -1)
					continue;
				if (!(j + f[i] > u || k + t[i] > m))
					maxi = max(maxi, dp[i + 1][j + f[i]][k + t[i]] = max(dp[i + 1][j + f[i]][k + t[i]], dp[i][j][k] + v[i]));

				maxi = max(maxi, dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]));
			}
		}
	}

	cout << maxi << endl;
	cin >> maxi;
}