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

#define MAXN 11

int c[MAXN], d[MAXN], q[MAXN][MAXN], amt[MAXN];
int cnt[MAXN];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &d[i]);
		for (int j = 0; j < n; j++)
			scanf("%d", &q[i][j]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &amt[i]);
	}

	int mini = INT_MAX;
	for (int i = 0; i < 1 << m; i++) {
		memset(cnt, 0, sizeof cnt);
		int cost = 0;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1)
			{
				cost += d[j];
				for (int k = 0; k < n; k++)
					cnt[k] += q[j][k];
			}
		}
		for (int j = 0; j < n; j++) {
			if (cnt[j] > amt[j])goto outer;
			cost += c[j] * (amt[j] - cnt[j]);
		}
		mini = min(mini, cost);

	outer:continue;
	}

	printf("%d\n", mini);
	cin >> n;
}