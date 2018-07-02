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

#define MOD 1000000007

#define MAXH 110
#define MAXL 100010

ll dp[2][MAXL][MAXH];
bool map[MAXL][MAXH];

int h, l;

bool git(int x, int y) {
	if (x < 0 || y < 0 || y > h || x > l)return false;
	return map[x][y];
}

int main() {
	int n, s; scan(n); scan(h); scan(l); scan(s);
	for (int i = 0; i < n; i++) {
		int x, y; scan(x); scan(y);
		map[x][y] = true;
	}

	//printf("%lld\n", ways(0, s));

	dp[0][0][s] = 1;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < h; j++)  {
			dp[0][i][j] %= MOD;
			dp[1][i][j] += dp[0][i][j];
		}
		for (int j = 0; j < h; j++)  {
			dp[0][i][j] %= MOD;
			if (git(i + 1, j))
				if (git(i + 1, j + 1))
					dp[1][i][j + 1] += dp[0][i][j];
		}
		for (int j = h - 1; j >= 0; j--) {
			dp[0][i][j] %= MOD;
			if (git(i + 1, j))
				if (git(i + 1, j - 1))
					dp[1][i][j - 1] += dp[0][i][j];
		}
		for (int j = 0; j < h; j++) {
			dp[1][i][j] %= MOD;
			if (j != 0 && !git(i + 1, j - 1))
				dp[0][i + 1][j - 1] += dp[1][i][j];

			if (j != h - 1 && !git(i + 1, j + 1))
				dp[0][i + 1][j + 1] += dp[1][i][j];

			if (!git(i + 1, j))
				dp[0][i + 1][j] += dp[1][i][j];
		}
	}

	ll tot = 0;
	for (int i = 0; i < h; i++)
		tot = (tot + dp[0][l][i]) % MOD;

	printf("%lld\n", tot);

	cin >> n;
}