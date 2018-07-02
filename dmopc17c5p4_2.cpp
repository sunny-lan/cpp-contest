#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAXN 511
//idx, over, lft
ll dp[2][MAXN][MAXN];
ll psa[2][MAXN][MAXN];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	dp[0][0][k] = 1;
	for(int idx = 0; idx < n; idx++) {
		int cur = idx % 2,
			nxt = (idx + 1) % 2;
		memset(dp[nxt], 0, sizeof dp[nxt]);
		memset(psa[nxt], 0, sizeof psa[nxt]);
		for(int over = 0; over <= n; over++) {
			for(int lft = 0; lft <= k; lft++) {
				psa[cur][over][lft + 1] += psa[cur][over][lft];
				psa[cur][over][lft + 1] %= MOD;

				dp[cur][over][lft] += psa[cur][over][lft];
				dp[nxt][over][lft] %= MOD;

				dp[nxt][over][lft] += dp[cur][over][lft];
				dp[nxt][over][lft] %= MOD;

				dp[nxt][over + 1][lft] += dp[cur][over][lft];
				dp[nxt][over + 1][lft] %= MOD;

				if(over > 0) {
					psa[nxt][over - 1][max(0, lft - (over - 1))] += dp[cur][over][lft];
					psa[nxt][over - 1][max(0, lft - (over - 1))] %= MOD;

					psa[nxt][over - 1][lft + 1] -= dp[cur][over][lft];
					psa[nxt][over - 1][lft + 1] %= MOD;
					psa[nxt][over - 1][lft + 1] += MOD;
					psa[nxt][over - 1][lft + 1] %= MOD;
				}
			}
		}
	}

	printf("%lld\n", (dp[n % 2][0][0]+psa[n % 2][0][0])%MOD);
}
