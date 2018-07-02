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

#define MAXN 10010

int p[MAXN];
double dp[4][MAXN];

double x[MAXN];
double y[MAXN];

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < MAXN; j++)
			dp[i][j] = INFINITY;

	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++)
		scan(p[i]);

	for (int i = 0; i < n; i++) {
		if (i + 3 <= n)
			x[i] = p[i] + p[i + 1] + p[i + 2] - min(min(p[i], p[i + 1]), p[i + 2]);
		if (i + 2 <= n)
			y[i] = p[i] + p[i + 1] - min((double)p[i], (double)p[i + 1]) / 2;
	}

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int ptr[3] = { 0,0,0 };
		int m0 = i % 4;
		int m1 = (i - 1 + 4) % 4;
		int m2 = (i - 2 + 4) % 4;
		int m3 = (i - 3 + 4) % 4;
		for (int j = 0; j < k; ) {
			int best = -1;
			double mini = INFINITY;
			if (i - 1 >= 0) {
				double alt = dp[m1][ptr[0]] + p[i - 1];
				if (alt < mini)
					mini = alt, best = 0;
			}
			if (i - 2 >= 0) {
				double alt = dp[m2][ptr[1]] + y[i - 2];
				if (alt < mini)
					mini = alt, best = 1;
			}
			if (i - 3 >= 0) {
				double alt = dp[m3][ptr[2]] + x[i - 3];
				if (alt < mini)
					mini = alt, best = 2;
			}
			if (best == -1)break;
			dp[m0][j] = mini;
			ptr[best]++;
			if (j > 0 && mini == dp[m0][j - 1])continue;
			j++;
		}
	}
	double res = dp[n % 4][k - 1];
	if (res == INFINITY)printf("-1\n");
	else	printf("%.1f\n", res);
	cin >> res;
}