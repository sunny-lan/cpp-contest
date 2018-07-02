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

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 200000
#define MAXV 101



int dp[MAXN][MAXV];
int v[MAXN];

int main() {
	memset(dp, 0x3f, sizeof dp);
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		int minbot = INT_MAX;
		for(int ch = 100; ch >= 0; ch--) {
			int dv = ch - v[i];
			int mini = minbot;
			for(int ph = 0; ph <= ch; ph++) {
				int bc = max(0, b * (ch - ph));
				mini = min(mini, dp[i][ph] + bc);
			}
			minbot = min(minbot, dp[i][ch]);
			dp[i + 1][ch] = mini + c * dv * dv + a * ch;
		}
	}
	int res = INT_MAX;
	for(int i = 0; i <= 100; i++)
		res = min(res, dp[n][i]);
	printf("%d\n", res);
}
