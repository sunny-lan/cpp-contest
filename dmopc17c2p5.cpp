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

#define MAXN 101

int dp[MAXN][MAXN][MAXN];

int K;

int f(int i, int j, int rm1) {
	if (j == 0)return i % 2;
	int &res = dp[i][j][rm1];
	if (res != -1)return res;
	if (i % 2 == 0) {
		res = 0;
		for (int rm = 1; rm <= min(rm1, j); rm++)
			res = max(res, f(i + 1, j - rm, rm + K));
	}
	else {
		res = 1;
		for (int rm = 1; rm <= min(rm1, j); rm++)
			res = min(res, f(i + 1, j - rm, rm + K));
	}
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);

	ll _k; scan(_k);
	int x, y; scan(x); scan(y);
	int tmp = max(x, y);
	x = min(x, y);
	y = tmp;
	K = (int)min(_k, (ll)y);

	int cnt = 0;
	for (int i = x; i <= y; i++)
		if (f(0, i, 1))
			cnt++;
	printf("%d\n", cnt);
}