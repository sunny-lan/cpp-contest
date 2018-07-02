#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 2002
#define MAXT 10002

int dp[2][MAXT];

int p[4][MAXN];
int v[4][MAXN];

int main() {
	memset(dp[0], -1, sizeof dp[0]);
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> p[j][i] >> v[j][i];
		p[3][i] = v[3][i] = 0;
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int idx = i % 2;
		int idxN = (i + 1) % 2;
		memset(dp[idxN], -1, sizeof dp[idxN]);
		for (int j = 0; j <= t; j++)
			if (dp[idx][j] != -1)
				for (int k = 0; k < 4; k++) {
					int l = j + p[k][i];
					if (l <= t)
						dp[idxN][l] = max(dp[idxN][l], dp[idx][j] + v[k][i]);
				}
	}
	int maxi = 0;
	for (int i = 0; i <= t; i++)
		maxi = max(maxi, dp[n%2][i]);
	cout << maxi << endl;
	cin >> n;
	return 0;
}