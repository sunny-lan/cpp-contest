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

#define MAXN 2000001

ll dp[MAXN];
ll psa[MAXN];

int main() {
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	int n, l; scan(n); scan(l);
	int j = 0;
	for (int i = 1; i <= n; i++) {
		scan(psa[i]);
		psa[i] += psa[i - 1];
		int t = 0;
		for (; j < i; j++) {
			ll alt = dp[j] + (i - j -1+ psa[i ] - psa[j] - l)*(i-j-1+psa[i ] - psa[j] - l) ;
			if (alt < dp[i]) {
				dp[i] = alt;
				t = j;
			}
		}
		j = t;
	}
	printf("%lld\n", dp[n]);
	cin >> j;
}