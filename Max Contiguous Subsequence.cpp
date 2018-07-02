#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 10001

int vals[MAXN];

int dp[2][MAXN+1];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = max( vals[i - 1], dp[0][i - 1] + vals[i - 1]);
		dp[1][i] = max(dp[1][i - 1], dp[0][i - 1]);
	}

	cout << "Out:"<< max(dp[0][n], dp[1][n]) << endl;

	cin >> n;

	return 0;
}