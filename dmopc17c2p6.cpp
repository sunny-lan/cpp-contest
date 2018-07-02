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

#define MAXN 2001

int n;
int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN][2];

int f(int i, int j, int ch) {
	if (i == n)return INT_MAX;
	int &res = dp[i][j][ch];
	if (res != -1)return res;
	if (ch == 0) {
		//continue
		res = max(res, min(f(i + 1, j, 0), a[i]));

		//switch
		if (j > 0)
			res = max(res, min(f(i + 1, j - 1, 1), b[i]));
	}
	else {
		res = max(res, min(f(i + 1, j, 1), b[i]));

		if (j > 0)
			res = max(res, min(f(i + 1, j - 1, 0), a[i]));
	}
	return res;
}

#define MAXN2 200010

pii pma[MAXN2];
pii pmb[MAXN2];

int main() {
	memset(dp, -1, sizeof dp);
	scan(n);
	for (int i = 0; i < n; i++)
		scan(a[i]);

	for (int i = 0; i < n; i++)
		scan(b[i]);
	/*if (n <= 2000) {
		for (int i = 0; i <= n; i++) {
			printf("%d\n", f(0, i, 0));
		}
	}
	else*/
	{
		for (int i = 0; i < n; i++) {
			pma[i] = { a[i], i };
			pmb[i] = { b[i], i };
		}
		for (int i = n - 1; i >= 1; i--) {
			pma[i - 1] = min(pma[i - 1], pma[i]);
			pmb[i - 1] = min(pmb[i - 1], pmb[i]);
		}
		bool ch = false;
		int curr = 0;
		int mini = INT_MAX;
		for (int i = 0; i <= n; i++) {
			if (ch) {
				printf("%d\n", min(mini,pma[curr].first));
				pii next = pma[curr];

			}
			else {
				printf("%d\n", min(mini, pmb[curr].first));
			}
		}
	}
	cin >> n;
}