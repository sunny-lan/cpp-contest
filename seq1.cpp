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
#define MOD 1000000007


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

//finds a^k mod m
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

int main() {
	ll n; scan(n);
	ll cust = pow_mod(2, n, MOD);
	printf("%lld", ((cust-1) * 7 + cust + 2) % MOD);
	cin >> n;
}