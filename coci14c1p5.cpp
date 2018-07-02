#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 1000001
#define MAXM 101
#define MAXK 501

typedef long long ull;

ull dp[MAXM][MAXK];

ull cnt[MAXM];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		++cnt[--b];
	}
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= k; j++)
			dp[i][j] = INT_MAX;

	dp[0][0] = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j] != INT_MAX) {
				for (int l = 0; j + l <= k; l++) {
					int parts = l + 1;
					ull basepartsize = cnt[i] / parts;
					ull remainder = cnt[i] % parts;
					ull alt = ((parts - remainder)*(basepartsize*(basepartsize + 1) / 2) + remainder*((basepartsize + 1)*(basepartsize + 2) / 2));
					//cout << "if " << i << " was split with " << l << " divides, would cost " << alt << endl;
					dp[i + 1][j + l] = min(dp[i + 1][j + l], alt+dp[i][j]);
				}
			}
		}
	}
	ull mini = INT_MAX;
	for (int i = 0; i <= k; i++) {
		mini = min(mini, dp[m][i]);
	}
	cout << mini << endl;
	cin >> mini;
	return 0;
}