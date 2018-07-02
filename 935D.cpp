#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 100010
#define MOD 1000000007ll

int n;ll m;
int a[MAXN];
int b[MAXN];

ll pos[MAXN];
ll rem;

#define NUM ll

//finds a*k mod m
NUM mult_mod(NUM a, NUM k, NUM m) {
	NUM res = 0;
	NUM cur = a;
	while (k) {
		if (k & 1)
			res += cur,
			res %= m;
		cur += cur;
		cur %= m;
		k >>= 1;
	}
	return res;
}

//finds a^k mod m (supports larger pows)
NUM pow_mod(NUM a, NUM k, NUM m) {
	NUM res = 1;
	NUM cur = a;
	while (k) {
		if (k & 1)
			res = mult_mod(cur, res, m);
		cur = mult_mod(cur, cur, m);
		k >>= 1;
	}
	return res;
}


//finds mod inverse of a for a prime
//aka finds x such that x*a = 1 (mod p)
NUM inverse_mod(NUM a, NUM p) {
	return pow_mod(a, p - 2, p);
}

ll dp[MAXN];

int main() {
	//freopen("C:\\Users\\sunny\\Desktop\\input.txt", "r", stdin);
	scanf("%d %I64d", &n, &m);
	rem = (m*m - m) / 2;
	rem %= MOD;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	dp[n] = 0, pos[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		pos[i] = pos[i + 1];
		if (a[i] == 0)
			pos[i] *= m, pos[i] %= MOD;
		if (b[i] == 0)
			pos[i] *= m, pos[i] %= MOD;

		ll res = 0;
		if (a[i] == 0 && b[i] == 0) {
			res = rem*pos[i + 1];
			res %= MOD;
			res += dp[i + 1] * m;
			res %= MOD;
		}
		else if (a[i] == 0) {
			res = (m - b[i])*pos[i + 1];
			res %= MOD;
			res += dp[i + 1];
			res %= MOD;
		}
		else if (b[i] == 0) {
			res = (a[i] - 1)*pos[i + 1];
			res %= MOD;
			res += dp[i + 1];
			res %= MOD;
		}
		else {
			if (a[i] > b[i])res = pos[i + 1];
			if (a[i] < b[i])res = 0;
			if (a[i] == b[i])res = dp[i + 1];
		}
		dp[i] = res;
	}
	printf("%I64d\n", dp[0] * inverse_mod(pos[0], MOD) % MOD);
	cin >> n;
}