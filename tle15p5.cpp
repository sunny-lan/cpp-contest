#ifdef DMOJ

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 2000
#define MOD 1000000007
#define NUM ll

NUM pow_mod(NUM a, NUM k, NUM m) {
	NUM res = 1;
	NUM cur = a;
	while (k) {
		if (k & 1)
			res *= cur,
			res %= m;
		cur *= cur;
		cur %= m;
		k >>= 1;
	}
	return res;
}
NUM inverse_mod(NUM a, NUM p) {
	return pow_mod(a, p - 2, p);
}
NUM c[MAXN];
NUM pascal_diag_mod(NUM n, int k, NUM p) {
	c[0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		c[i] = c[i - 1];
		c[i] *= (n + i);
		c[i] %= p;
		c[i] *= inverse_mod(i, p);
		c[i] %= p;
	}
	return c[k];
}

int a[MAXN];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++)
		scan(a[i]);
	int m; scan(m);
	pascal_diag_mod(m-1, n, MOD);
	for (int i = 0; i < n; i++) {
		ll r = 0;
		for (int j = 0; j <=i; j++) {
			r += a[j] * c[i - j];
			r%= MOD;
		}
		printf("%lld ", r);
	}
	printf("\n");
	//cin >> n;
}