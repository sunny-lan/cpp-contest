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
NUM pow_mod_big(NUM a, NUM k, NUM m) {
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
	return pow_mod_big(a, p - 2, p);
}

#define MAXN 200001
NUM c[MAXN];

//calculates row of pascals triangle
// aka n Cr k, n Cr k-1, n Cr k-2, ... n Cr 0
// c[i] = n cR i for i from 0 to k
NUM pascal_row(NUM n, int k) {
	c[0] = 1;
	for (int i = 0; i < k; ++i)
	{
		c[i + 1] = c[i];
		c[i + 1] *= (n - i);
		c[i + 1] /= (i + 1);
	}
	return c[k];
}
//calculates row of pascals triangle mod a prime
NUM pascal_row_mod(NUM n, int k, NUM p) {
	c[0] = 1;
	for (int i = 0; i < k; ++i)
	{
		c[i + 1] = c[i];
		c[i + 1] *= (n - i);
		c[i + 1] %= p;
		c[i + 1] *= inverse_mod(i + 1, p);
		c[i + 1] %= p;
	}
	return c[k];
}

#define MAXN2 2001
ll rows[MAXN2][MAXN2];

int main() {
	ll n, m; cin >> n >> m;
	if (n <= 2000) {
		rows[0][0] = 1;
		for (int row = 1; row <= n; row++) {
			for (int dst = 0; dst <= row; dst++) {
				ll a=0;
				if (dst > 0)a = rows[row - 1][dst - 1];
				rows[row][dst] = (a + rows[row - 1][dst])%m;
			}
		}
		for (int i = 0; i <= n; i++)
			printf("%lld\n", rows[n][i]);
	}
	else {
		pascal_row_mod(n, n, m);
		for (int i = 0; i <= n; i++)
			printf("%lld\n", c[i] % m);
	}
	cin >> n;
}