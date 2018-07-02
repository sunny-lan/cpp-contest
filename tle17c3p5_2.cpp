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

vector<int> dimension;

void construct(vector<ll> &psa) {
	int d = 1;
	for (int i = 0; i < dimension.size(); i++) {
		vector<ll> alt(psa.size());
		int dim = dimension[i] * d;
		for (int j = 0; j < psa.size(); j++) {
			alt[j] = psa[j];
			if (j - d >= 0 && (j - d) / dim == j / dim)
				alt[j] += psa[j - d];
			if (j + d < psa.size() && (j + d) / dim == j / dim)
				alt[j] += psa[j + d];
		}
		d *= dimension[i];
		psa = alt;
	}
}

int main() {
	int n; scan(n);
	int base = 1;
	for (int i = 0; i < n; i++) {
		int sz; scan(sz);
		base *= sz;
		dimension.push_back(sz);
	}
	reverse(dimension.begin(), dimension.end());

	vector<ll> psa;
	vector<ll> orig;
	psa.reserve(base);
	for (int i = 0; i < base; i++) {
		ll x; scan(x);
		psa.push_back(x);
		orig.push_back(x);
	}

	construct(psa);

	for (int i = 0; i < base; i++)
		printf("%lld\n", psa[i] - orig[i]);
	cin >> n;
}