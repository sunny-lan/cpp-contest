#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 2005

ll _dp[MAXN][MAXN * 2];
ll &dp(int i, int j) {
	return _dp[i][j + MAXN];
}
int v[MAXN];

int n;
ll a, b;
ll cst(int j) {
	ll cst = 1ll << 60;
	if(j >= 0)
		cst = a * j;
	if(j <= 0)
		cst = min(cst, -b * j);
	return cst;
}

int main() {
	memset(_dp, 0x3f, sizeof _dp);
	scanf("%d%lld%lld", &n, &a, &b);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v, v + n);
	for(int i = -n; i <= n; i++)
		dp(0, i) = cst(i);
	for(int i = 1; i < n; i++) {
		int k = -n;
		ll mini = 1ll << 60;
		for(int j = -n; j <= n; j++) {
			while(k  < n && k + v[i - 1] < j + v[i])
				mini = min(mini, dp(i - 1, k)), k++;
			dp(i, j) = mini + cst(j);
		}
	}
	ll res = 1ll << 60;
	for(int j = -n; j <= n; j++)
		res = min(res, dp(n - 1, j));
	printf("%lld\n", res);
}
