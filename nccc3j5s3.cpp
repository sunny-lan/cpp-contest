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

double x[16], y[16];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}

	double mini = INFINITY;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i] == x[j] && y[i] == y[j])continue;

			double mijx = (x[i] + x[j]) / 2,
				mijy = (y[i] + y[j]) / 2;
			double furthest = 0;
			for (int k = 0; k < n; k++) {
				double dx = mijx - x[k], dy = mijy - y[k];
				furthest = max(furthest, dx*dx + dy*dy);

				if (x[i] == x[k] && y[i] == y[k])continue;
				if (x[k] == x[j] && y[k] == y[j])continue;

				//stuff for 3 lines
				//find jk midpoint
				double mjkx = (x[j] + x[k]) / 2,
					mjky = (y[j] + y[k]) / 2;
				//convert to ax+by=c
				double ija = y[j] - y[i],
					ijb = x[i] - x[j],
					ijc = ija*x[j] + ijb*y[j];
				double jka = y[k] - y[j],
					jkb = x[j] - x[k],
					jkc = jka*x[j] + jkb*y[j];
				//convert to perp bisect
				double pija = -ijb,
					pijb = ija,
					pijc = pija*mijx + pijb*mijy;
				double pjka = -jkb,
					pjkb = jka,
					pjkc = pjka*mjkx + pjkb*mjky;
				double det = pija*pjkb - pjka*pijb;
				if (det == 0) {
					//Lines are parallel
				}
				else {
					double cx = (pjkb*pijc - pijb*pjkc) / det,
						cy = (pija*pjkc - pjka*pijc) / det;
					double f2 = 0;
					for (int l = 0; l < n; l++) {
						double dx1 = cx - x[l], dy1 = cy - y[l];
						f2 = max(f2, dx1*dx1 + dy1*dy1);
					}
					mini = min(mini, f2);
				}
			}
			mini = min(mini, furthest);
		}
	}
	if (mini == INFINITY)mini = 0;
	mini = sqrt(mini);
	printf("%lf", mini);
	cin >> n;
}