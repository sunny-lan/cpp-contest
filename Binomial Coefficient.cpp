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

#define MAXN 2000
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

//calculates diagonal of pascals triangle
// aka n+k Cr k, n+k-1 Cr k-1, n+k-2 Cr k-2, ... n Cr 0
// c[i] = n+i cR i for i from 0 to k
NUM pascal_diag(NUM n, int k) {
	c[0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		c[i] = c[i - 1];
		c[i] *= (n + i);
		c[i] /= i;
	}
	return c[k];
}

//calculates diagonal of pascals triangle mod a prime
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

//finds gcd of two numbers
NUM gcd(NUM a, NUM b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	cout << pascal_diag_mod(3, 4, 1000000007) << endl;
	cin >> c[0];
}