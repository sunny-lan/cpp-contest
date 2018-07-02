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

#define MAXN 36

ll v[MAXN];

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++)
		scan(v[i]);
	for (int i = n; i < n + m; i++) {
		scan(v[i]);
		v[i] = -v[i];
	}
	unordered_map<ll, ll> a, b;
	int mid = (n + m) / 2;
	for (int i = 0; i < 1 << mid; i++) {
		ll s = 0;
		for (int j = 0; j < mid; j++)
			if ((i >> j) & 1)
				s += v[j];
		a[s]++;
	}
	for (int i = 0; i < 1 << (n + m - mid); i++) {
		ll s = 0;
		for (int j = mid; j < n + m; j++)
			if ((i >> (j - mid)) & 1)
				s += v[j];
		b[s]++;
	}
	ll t = 0;
	for (pair<ll,ll> s : a)
		t += s.second*b[-s.first];
	printf("%lld\n", t - 1);
	cin >> t;
}