#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 5010

int a[MAXN];
int psa[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), psa[i][m - 1] = dp[m][i] = (a[i]==1?0:1);

	for (int i = m - 1; i > 0; i--) {
		for (int j = 0; j < n; j++) {
			int nx = (j + 1) % n;
			int nm = min(m, i + k);
			int cnt = psa[nx][i] - psa[nx][nm];
			if (a[j] == 1) {
				if (cnt > 0)
					dp[i][j] = 1;
			}
			else {
				if (cnt == nm - i)
					dp[i][j] = 1;
			}
			psa[j][i - 1] = psa[j][i] + dp[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", dp[1][i]);
	printf("\n");

	cin >> n;
}