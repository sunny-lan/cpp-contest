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
#include <random>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ll pow_mod(ll x, ll n, ll p) {
	if (n == 0) return 1;
	if (n & 1)
		return (pow_mod(x, n - 1, p) * x) % p;
	x = pow_mod(x, n / 2, p);
	return (x * x) % p;
}

/* Takes as input an odd prime p and n < p and returns r
* such that r * r = n [mod p]. */
ll tonelli_shanks(ll n, ll p) {
	ll s = 0;
	ll q = p - 1;
	while ((q & 1) == 0) { q /= 2; ++s; }
	if (s == 1) {
		ll r = pow_mod(n, (p + 1) / 4, p);
		if ((r * r) % p == n) return r;
		return 0;
	}
	// Find the first quadratic non-residue z by brute-force search
	ll z = 1;
	while (pow_mod(++z, (p - 1) / 2, p) != p - 1);
	ll c = pow_mod(z, q, p);
	ll r = pow_mod(n, (q + 1) / 2, p);
	ll t = pow_mod(n, q, p);
	ll m = s;
	while (t != 1) {
		ll tt = t;
		ll i = 0;
		while (tt != 1) {
			tt = (tt * tt) % p;
			++i;
			if (i == m) return 0;
		}
		ll b = pow_mod(c, pow_mod(2, m - i - 1, p - 1), p);
		ll b2 = (b * b) % p;
		r = (r * b) % p;
		t = (t * b2) % p;
		c = b2;
		m = i;
	}
	if ((r * r) % p == n) return r;
	return 0;
}

int main() {
	
	int p; cin >> p;
	const int range_from = p+1;
	const int range_to = INT_MAX;
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(range_from, range_to);

	ll xor = 0;
	for (int i = 0; i < 10000; i++) {
		int num = distr(generator);
		cout << tonelli_shanks(num, p) << endl;
	}
	cout << xor << endl;
	cin >> p;
}

