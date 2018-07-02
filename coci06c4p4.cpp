#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAXN 1010
#define MAXC 10010

ll dp[MAXN][MAXC];
ll psa[MAXN][MAXC];

int main() {
	int n, c; scanf("%d %d", &n, &c);
	dp[0][0] = 1;
	psa[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c; j++) {
			dp[i][j] = psa[i - 1][j + 1] - psa[i - 1][max(0, j - i)];
			dp[i][j] = (dp[i][j] + MOD) % MOD;
		}
		for (int j = 0; j <= c; j++)
			psa[i][j + 1] = (psa[i][j] + dp[i][j])%MOD;
	}
	printf("%lld\n", dp[n][c] % MOD);
	cin >> n;
}