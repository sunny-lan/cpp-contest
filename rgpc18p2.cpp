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

int main() {
	int n; double s; scanf("%d %lf", &n, &s);
	int ex = 0, gr = 0, go = 0, bd = 0, ms = 0, mxcmb = 0, cmb = 0;
	for (int i = 0; i < n; i++) {
		cmb++;
		int t; scanf("%d", &t);
		t = abs(t);
		if (t >= 0 && t <= 50)
			ex++;
		else if (t >= 51 && t <= 100)
			gr++;
		else if (t >= 101 && t <= 150)
			go++;
		else if (t >= 151 && t <= 200)
			bd++;
		else if (t > 200)
			ms++, cmb = 0;
		mxcmb = max(mxcmb, cmb);
	}
	double ns = 1.5*ex + 1.0*gr + 1.0*go + 0.5*bd - 1.0*ms+0.5*mxcmb;
	printf("%.1lf\n", max(ns - s,0.0));
	cin >> n;
}