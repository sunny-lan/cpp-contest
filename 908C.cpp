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

#define MAXN 1000

int x[MAXN];
double y[MAXN];

int main() {
	int n, r; scan(n); scan(r);
	for (int i = 0; i < n; i++) {
		scan(x[i]);
		y[i] = r;
		for (int j = 0; j < i; j++) {
			double dx = abs(x[i] - x[j]);
			double hyp = 2 * r;
			if (dx > hyp)continue;
			double dy = sqrt(hyp*hyp-dx*dx);
			y[i] = max(y[i], dy + y[j]);
		}
	}
	for (int i = 0; i < n; i++)printf("%lf ", y[i]);
	cin >> n;
}