#include <bits/stdc++.h>
using namespace std;

#define MAXN 10101
#define MAXK 502

int dp[MAXN][MAXK];
int psa[MAXN];
int a[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++) {
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		int n, k, w;
		scanf("%d %d %d", &n, &k, &w);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		psa[0] = 0;
		for(int i = 0; i < n + w; i++)
			psa[i + 1] = psa[i] + a[i];
		int maxi = 0;
		for(int i = 1; i < n + w; i++) {
			for(int j = 1; j <= k; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				int cur = i - w;
				do {
					int act = max(0, cur);
					int cnt = (i - act+w-1) / w ;
					if(j - cnt < 0)
						break;
					dp[i][j] = max(dp[act][j - cnt] + psa[i] - psa[act], dp[i][j]);
					cur--;
				} while(cur >= 0);
				maxi = max(maxi, dp[i][j]);
			}
		}
		printf("%d\n", maxi);
	}
}
