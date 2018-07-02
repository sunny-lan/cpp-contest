#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 510
#define MOD 1000000007

int a[MAXN], b[MAXN];
int all[MAXN * 2];

unordered_map<int, int> ord;
int n;
ll dp[MAXN][MAXN * 2];
ll f(int i, int j) {
	if (i == n)
		return j > 0 ? 1 : 0;
	ll &res = dp[i][j];
	if (res != -1)return res;
	res = f(i + 1, j);
	for (int nxt = max(ord[a[i]], j + 1); nxt < ord[b[i]]; nxt++)
		res += f(i + 1, nxt)*(all[nxt + 1] - all[nxt] + 1), res %= MOD;
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		all[i * 2] = a[i];
		all[i * 2 + 1] = b[i];
	}
	sort(all, all + n * 2);
	int nl = unique(all, all + n * 2) - all;
	for (int i = 0; i < nl; i++)
		ord[all[i]] = i + 1;
	printf("%lld", f(0, 0));
	cin >> n;
}