#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MOD 1000000007
#define MAXN 110

int n, k;
ll dp[MAXN][MAXN][MAXN][2];

ll f(int l, int h, int i, int d) {
	if (i > k)return 0;
	if (l + h == 0)return d;
	ll &res = dp[l][h][i][d];
	if (res != -1)return res;
	res = 0;
	for (int j = 0; j < h; j++)
		res += f(l + j, h - j - 1, i + 1, d | (i + 1 == k ? 1 : 0)),
		res %= MOD;

	for (int j = 0; j < l; j++)
		res += f(j, h + (l - j - 1), 1, d | (k == 1 ? 1 : 0)),
		res %= MOD;

	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &k);
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += f(i, n - i - 1, 1, (k == 1 ? 1 : 0)),
		res %= MOD;
	printf("%lld\n", res);
	cin >> res;
}