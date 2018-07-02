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

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXG 400

int g;
double x[MAXG];
double bot[MAXG], top[MAXG];

double f(double x, double x1, double y1, double x2, double y2) {
	return (x - x1)*(y1 - y2) / (x1 - x2) + y1;
}

int maxi = -1;
double ba, bb;

void cnt(double x1, double y1, double x2, double y2) {
	int res = 0;
	for (int i = 0; i < g; i++) {
		double inter = f(x[i], x1, y1, x2, y2);
		if (inter >= bot[i] && inter <= top[i])res++;
	}
	if (res < maxi)return;
	double ra = f(0, x1, y1, x2, y2),
		rb = f(100, x1, y1, x2, y2);
	if (ra < 0 || rb < 0)return;
	if (res == maxi) {
		if (ra > ba)return;
		else if (ra == ba)
			if (rb > bb)return;
	}
	maxi = res;
	ba = ra, bb = rb;
}

int main() {
	scan(g);
	for (int i = 0; i < g; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		x[i] = a, bot[i] = b, top[i] = c;
	}
	if (g == 1)
		maxi = 1, ba = bb = bot[0];
	else
		for (int i = 0; i < g; i++) {
			cnt(0, 0, x[i], bot[i]);
			for (int j = i + 1; j < g; j++) {
				cnt(x[i], bot[i], x[j], bot[j]);
				cnt(x[i], top[i], x[j], top[j]);
				cnt(x[i], bot[i], x[j], top[j]);
				cnt(x[i], top[i], x[j], bot[j]);
			}
		}
	printf("%d\n%lf\n%lf\n", maxi, ba, bb);
}