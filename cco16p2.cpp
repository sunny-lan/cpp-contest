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

#define MAXN 4000

int x[MAXN];
int y[MAXN];
int w[MAXN];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scan(x[i]); scan(y[i]); scan(w[i]);
	}

	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> pts;
		int ue = 0, de = 0, ui = 0, di = 0;
		for (int j = 0; j < n; j++)if (j != i) {
			double slope = (double)(y[j] - y[i]) / (double)(x[j] - x[i]);
			pts.push_back({ slope, j });
			
			if (y[j] < y[i])
				de += w[j];
			else if (y[j] == y[i]) {
				if (x[j] < x[i])
					ui += w[j];
				else
					di += w[j];
			}
			else
				ue += w[j];
		}

		sort(pts.begin(), pts.end());

	}
}