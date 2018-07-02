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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 420

bool gr[MAXN][MAXN];
int psa[MAXN][MAXN];
int dp[2][MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c; cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string row; cin >> row;
		for (int j = 0; j < c; j++)
			if (gr[i][j] = row[j] == 'X')
				psa[i][j + 1] = psa[i][j] + 1;
			else psa[i][j + 1] = psa[i][j];
	}

	int maxi = 0;
	for (int i = 0; i < r; i++) {
		int i1 = i % 2;
		int i2 = (i + 1) % 2;
		memset(dp[i2], 0, sizeof dp[i2]);
		for (int j = 0; j < c; j++) for (int k = j + 1; k <= c; k++)
			if (psa[i][k] - psa[i][j] == 0)
				dp[i2][j][k] = max(dp[i2][j][k], dp[i1][j][k] + 1),
				maxi = max(maxi, dp[i2][j][k] * 2 + (k - j) * 2);
	}

	printf("%d\n", maxi - 1);
	cin >> r;
}