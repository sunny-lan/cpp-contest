#include <iostream>
#include <cstring>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAX(a,b)(a>b?a:b)
int can[4096];
int dp[2][4096];
long long v[2][4096][64];
int num[2][4096];
int n, p;
int main()
{
	memset(dp, -1, sizeof(dp));
	int i;
	scan(n);
	scan(p);
	for (i = 0; i < n; i++) {
		scan(can[i]);
	}
	int curr = 0, next = 1, max = 0, taken = 0;
	long long in[64];
	dp[0][0] = 0;
	num[0][0] = 0;
	for (i = 0; i < n; i++) {
		memset(dp[next], -1, sizeof(dp[next]));
		if (dp[curr][0] > max) {
			max = dp[curr][0];
			taken = num[curr][0];
			memcpy(in, v[curr][0], sizeof(in));
		}
		for (int j = 0; j < p; j++) {
			if (dp[curr][j] != -1) {
				if (dp[curr][j] > dp[next][j]) {
					dp[next][j] = dp[curr][j];
					num[next][j] = num[curr][j];
					memcpy(v[next][j], v[curr][j], sizeof(v[next][j]));
				}
				int t = (j + can[i]) % p;
				if (dp[curr][j] + can[i] > dp[next][t]) {
					num[next][t] = num[curr][j] + 1;
					dp[next][t] = dp[curr][j] + can[i];
					memcpy(v[next][t], v[curr][j], sizeof(v[next][t]));
					v[next][t][i >> 6] |= 1LL << (i & 0b111111);
				}
			}
		}
		next = curr;
		curr = 1 - curr;
	}
	if (dp[curr][0] > max) {
		max = dp[curr][0];
		taken = num[curr][0];
		memcpy(in, v[curr][0], sizeof(in));
	}
	printf("%d\n%d\n", max, taken);
	for (i = 0; i < n; i++) if ((in[i / 64] >> (i % 64)) & 1) printf("%d ", i + 1);
	printf("\n");
	return 0;
}