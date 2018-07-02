#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1001
#define MAXV 10000

int seq[MAXN];

int dp[MAXN][MAXV + 1];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= MAXV; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (seq[i] > j)
				dp[i + 1][seq[i]] = max(dp[i + 1][seq[i]], dp[i][j] + 1);
		}
	}

	int maxi = 0;
	for (int j = 0; j <= MAXV; j++) {
		maxi = max(maxi, dp[n][j]);
	}

	cout << maxi << endl;
	cin >> maxi;

	return 0;
}