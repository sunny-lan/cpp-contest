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
#include<set>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 300000

int c[MAXN];
pii j[MAXN];
bool pred(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++) {
		int m, v; scan(m); scan(v);
		j[i] = { v,m };
	}
	for (int i = 0; i < k; i++)scan(c[i]);
	sort(j, j + n, pred);
	sort(c, c + k);
	multiset<pii> b;
	int ptr = 0;
	ll tot = 0;
	for (int i = 0; i < k; i++) {
		while (ptr<n && j[ptr].second <= c[i])
			b.insert(j[ptr++]);
		if (!b.empty()) {
			auto e = b.end();
			e--;
			tot += e->first;
			b.erase(e);
		}
	}
	printf("%lld\n", tot);
	cin >> n;
}