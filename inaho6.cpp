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
#include <complex>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	ll x; scan(x);
	complex<double> z(1,0);
	complex<double> convergence(0.438282936727032, 0.360592471871386);
	double err = 0.00005;
	complex<double> img(0, 1);
	for (int i = 0; i < x; i++) {
		z = pow(img, z);
		if (abs(z.imag() - convergence.imag()) < err &&
			abs(z.real() - convergence.real()) < err)
			break;
	}
	printf("%lf\n%lf\n", z.real(), z.imag());
	cin >> x;
}