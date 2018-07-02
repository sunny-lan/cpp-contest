#include <iostream>

using namespace std;

#define MAXN 5000000

bool dp[2][MAXN];

int main() {
	int n;
	cin >> n;
	dp[0][0] = true;

	for (int i = 0; i < n; i++) {
		if (dp[0][i]) {
			dp[1][i + 3] = true;
			dp[1][i + 1] = true;
			dp[1][i + 4] = true;
		}
		if (dp[1][i]) {
			dp[0][i + 3] = true;
			dp[0][i + 1] = true;
			dp[0][i + 4] = true;
		}
	}

	cout << dp[0][n] << "," << dp[1][n] << endl;
}