#include <bits/stdc++.h>
using namespace std;

#define MAXN 301

int n, t;
int x[MAXN];
int dp[2][MAXN][MAXN];
int k;

int f(int s, int i, int j) {
	int sz = j - i + 1;
	if(sz == k)
		return 0;
	int &res = dp[s][i][j];
	if(res != -1)
		return res;
	res = 1<<30;
	int cur = x[s ? i : j];
	if(i > 0)
		res = min(f(1, i - 1, j) + (k - sz) * abs(cur - x[i - 1]), res);
	if(j < n - 1)
		res = min(f(0, i, j + 1) + (k - sz) * abs(x[j + 1] - cur), res);
	return res;
}

int main() {
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	x[n] = 0, n++;
	sort(x, x + n);
	int st;
	for(int i = 0; i < n; i++)
		if(x[i] == 0) {
			st = i;
			break;
		}
	int res = 0;
	for(k = 1; k <= n; k++) {
		memset(dp, -1, sizeof dp);
//		printf("k=%d f=%d\n", k, f(0,st,st));
		res = max(res, (k-1) * t - f(0, st, st));
	}
	printf("%d\n", res);
}
