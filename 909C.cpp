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

#define MAXN 5001
#define MOD 1000000007
char c[MAXN];

int n;
int dp[MAXN][MAXN][2];

int f(int i, int j, int prev) {
	if (i == n)
		return 1;
	ll res = dp[i][j][prev];
	if (res != -1)
		return res;
	res = 0;
	if (c[i] == 's')
		res = f(i + 1, j, 0);
	else {
		if (prev == 1)
			res = f(i + 1, j + 1, 1);
		else
			for (int k = 1; k <= j + 1; k++)
				res += f(i + 1, k, 1), res %= MOD;
	}
	return dp[i][j][prev] = res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scan(n);
	for (int i = 0; i < n; i++)
		scanf(" %c", &c[i]);
	printf("%d\n", f(0, 0, 0));
	cin >> n;
}