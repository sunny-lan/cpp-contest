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

int main() {
	double r, x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2);
	double dx = x1 - x2, dy = y1 - y2;
	double x = sqrt(dx*dx + dy*dy);
	if (x >= r) {
		printf("%lf %lf %lf\n", x1, y1, r);
	}
	else {
		if (dx == 0 && dy == 0) {
			printf("%lf %lf %lf\n", (x1 + r) / 2, y1, r / 2);
		}
		else {
			double ans = (x + r) / 2;
			double ratio = ans / x;
			dx *= ratio, dy *= ratio;
			printf("%lf %lf %lf\n", x2 + dx, y2 + dy, ans);
		}
	}
	cin >> r;
}