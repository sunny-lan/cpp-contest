#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 5001
#define MAXC 18446744073709551615ull

typedef unsigned long long ull;

ull dp[MAXN][MAXN];

ull c[MAXN];
int d[MAXN];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> d[i];
		for (int j = 0; j <= n; j++)
			dp[i][j] = MAXC;
	}
	for (int j = 0; j <= n; j++)
		dp[n][j] = MAXC;

	dp[1][d[0]] = c[0];

	for (int i = 0; i < n; i++) {
		for (int j = i; j <= n; j++) {
			if (dp[i][j] == MAXC)	continue;
			dp[i + 1][min(j + d[i], n)] = min(dp[i + 1][min(j + d[i], n)], dp[i][j] + c[i]);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		}
	}

	ull mini = MAXC;
	for (int i = 0; i <= n; i++)
		mini = min(mini, dp[n][i]);
	cout << mini << endl;
}