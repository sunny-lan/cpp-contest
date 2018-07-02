#include <bits/stdc++.h>
using namespace std;

#define MAXN 12
#define MAXB 4096
#define MOD 100000000

int r, c;
int g[MAXN];

int dp[MAXN][MAXB];
int f(int i, int j) {
	if(i == r)
		return 1;
	int &res = dp[i][j];
	if(res != -1)
		return res;
	res = 0;
	for(int cur = 0; cur < 1 << c; cur++)
		if((g[i] | cur) == g[i])
			if(j & cur == 0) {
				for(int j = 1; j < c; j++)
					if(1 & (cur >> j) & (cur >> (j - 1)))
						goto outer;
				res += f(i + 1, cur);
				res %= MOD;
			outer:
				continue;
			}
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);

	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			int cr;
			scanf("%d", &cr);
			g[i] |= cr << j;
		}
	printf("%d\n", f(0, 0));
}
