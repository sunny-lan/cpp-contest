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

//finds a^k mod m
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

// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(NUM d, NUM n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	NUM a = 2 + rand() % (n - 4);

	// Compute a^d % n
	NUM x = pow_mod(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	// Keep squaring x while one of the following doesn't
	// happen
	// (i)   d does not reach n-1
	// (ii)  (x^2) % n is not 1
	// (iii) (x^2) % n is not n-1
	while (d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)      return false;
		if (x == n - 1)    return true;
	}

	// Return composite
	return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(NUM n, NUM k)
{
	// Corner cases
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	NUM d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given nber of 'k' times
	for (NUM i = 0; i < k; i++)
		if (miillerTest(d, n) == false)
			return false;

	return true;
}

#define k 3

int main() {
	ll n; scan(n);
	if (n!=2 && n % 2 == 0)n++;
	for (; !isPrime(n, k); n+=2);
	printf("%lld\n", n);
}