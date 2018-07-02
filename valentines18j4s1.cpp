#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int best , maxi = -1;
	for (int i = 1;; i++) {
		string conv = to_string(i);
		string rev = conv;
		reverse(rev.begin(), rev.end());
		string pal1 = conv + rev, pal2 = conv + rev.substr(1, rev.length() - 1);
		int p1v = atoi(pal1.c_str()), p2v = atoi(pal2.c_str());
		if (p2v >= m)break;
		if (p1v >= n && p1v < m) {
			int alt = min(abs(p1v - n), abs(p1v - m));
			if (alt > maxi)
				best = p1v, maxi=alt;
			else if (alt == maxi)
				if (p1v > best)best = p1v;
		}
		if (p2v >= n && p2v < m) {
			int alt = min(abs(p2v - n), abs(p2v - m));
			if (alt > maxi)
				best = p2v, maxi = alt;
			else if (alt == maxi)
				if (p2v > best)best = p2v;
		}
	}
	printf("%d\n", best);
	cin >> n;
}