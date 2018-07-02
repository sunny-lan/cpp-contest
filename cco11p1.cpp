#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, ll> pdl;

#define MAXN 100000

pdl s[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lf", &s[i].second, &s[i].first);
	}
	ll ms; scanf("%lld", &ms);
	sort(s, s + n);
	double lst = 1;
	for (int i = 0; i < n; i++) {
		double dst = s[i].first - lst;
		double nxt = s[i].first + dst;
		if (s[i].second == ms) {
			printf("%d\n%d\n", (int)lst, (int)nxt);
			break;
		}
		lst = nxt+1;
	}
	cin >> n;
}