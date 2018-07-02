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

#define MAXN 200000

int x[MAXN];
int y[MAXN];

struct point {
	double x, y;
	point(double xi, double yi) {
		x = xi, y = yi;
	}
};

double sign(point p1, point p2, point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(point pt, point v1, point v2, point v3)
{
	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0.0;
	b2 = sign(pt, v2, v3) < 0.0;
	b3 = sign(pt, v3, v1) < 0.0;

	return ((b1 == b2) && (b2 == b3));
}

int main() {
	int n, xe; scan(n); scan(xe);
	bool xsame = true,
		ysame = true;
	for (int i = 0; i < n; i++) {
		scan(x[i]); scan(y[i]);
		if (i > 0) {
			if (x[i] != x[i - 1])
				xsame = false;
			if (y[i] != y[i - 1])
				ysame = false;
		}
	}

	if (n <= 1000) {
		int dis = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++)if (j != i) {
				if (PointInTriangle(point(x[i], y[i]), point(x[j], y[j]), point(0, 0), point(xe, 0))) {
					cnt++;
				}
			}
			dis += cnt*cnt;
		}
		printf("%d\n", dis);
	}
	else if (xsame) {
		printf("%d\n", n*(n - 1) / 2);
	}
	else if (ysame) {
		printf("0\n");
	}
}