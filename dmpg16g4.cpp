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

#define MAXN 100010

int a[MAXN];
int d[MAXN];
int nxt[MAXN];

int dp[2][MAXN];

int last[MAXN];

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++)
		last[i] = MAXN - 1;

	for (int i = 0; i < n; i++) {
		scan(a[i]);
		a[i]--;
		nxt[last[a[i]]] = i;
		last[a[i]] = i;
	}

	for (int i = 0; i < m; i++) {
		scan(d[i]);
		nxt[last[i]] = n;
	}

	for (int i = 0; i < n; i++) {
		dp[0][i + 1] = max(dp[0][i + 1], dp[0][i]);
		dp[1][i] = max(dp[1][i], dp[0][i]);
		dp[1][nxt[i]] = max(dp[1][nxt[i]], dp[1][i] + 1);
		dp[0][min(i + d[a[i]] + 1, n)] = max(dp[0][min(i + d[a[i]] + 1, n)], dp[1][i] + 1);
	}

	printf("%d\n", max(dp[0][n], dp[1][n]));

	cin >> n;
}