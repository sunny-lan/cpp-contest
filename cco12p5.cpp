#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool res[101];

int rnd(double d) {
	double nval = (double)((int)d);
	if (d - nval >= 0.5 - DBL_EPSILON)return d + 1;
	return d;
}

int main() {
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int p; scanf("%d", &p);
		for (int n = 1; n <= 100; n++) {
			int gl = rnd(((p*n) / 100)*100.0 / n);
			int gh = rnd(((p*n + 99) / 100)* 100.0 / n);
			if (gl != p && gh != p)res[n] = true;
		}
	}
	for (int n = 1; n <= 100; n++)if (!res[n]) {
		printf("%d\n", n); break;
	}
	cin >> m;
}