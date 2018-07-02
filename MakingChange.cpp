#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1000
#define MAXV 10001

int dp[MAXV];
int coin[MAXN];

int main() {
	int n;
	int c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i < MAXV; i++) {
		dp[i] = INT_MAX;
	}

	dp[0] = 0;
	for (int i = 0; i < c; i++) {
		if (dp[i] != INT_MAX)
			for (int j = 0; j < n; j++) {
				int newval = i + coin[j];
				if (newval <= c) {
					dp[newval] = min(
						dp[newval],
						dp[i] + 1
					);
				}
			}
	}

	if (dp[c] == INT_MAX)
		cout << -1 << endl;
	else
		cout << dp[c] << endl;
	cin >> c;
}