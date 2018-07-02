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

#define MAXN 1000010

ll dp[MAXN];
ll psa[MAXN];

int main() {
	int n, m, k; scan(n); scan(m); scan(k);
	ll w = 1;
	for (int i = 0; i < k; i++) {
		dp[i] = w;
		w *= m;
		psa[i + 1] = psa[i] + dp[i];
	}
	for (int i = k; i < n; i++) {
		dp[i] = (m - 1)*psa[i] - psa[i - k + 1];
		psa[i + 1] = psa[i] + dp[i];
	}
	printf("%lld\n", w - dp[n - 1]);
	cin >> n;
}