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

#define MAXN 100000

int dp[32];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int a; scan(a);
		int maxi = 0;
		for (int j = 0; j < 32; j++)
			if ((a >> j) & 1)
				maxi = max(maxi, dp[j] + 1);
		for (int j = 0; j < 32; j++)
			if ((a >> j) & 1)
				dp[j] = max(maxi, dp[j]);
	}
	int ans = 0;
	for (int i = 0; i < 32; i++)ans = max(dp[i], ans);
	printf("%d\n", ans);
	cin >> n;
}