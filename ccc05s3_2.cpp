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

#define MAXS 1025

int a[MAXS][MAXS];
int b[MAXS][MAXS];
int tmp[MAXS][MAXS];

int main() {
	int n; scanf("%d", &n);
	int cr = 1, cc = 1;
	a[0][0] = 1;
	for (int mt = 0; mt < n; mt++) {
		int r, c; scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf("%d", &b[i][j]);
		for (int i = 0; i < cr; i++)
			for (int j = 0; j < cc; j++)
				for (int k = 0; k < r; k++)
					for (int l = 0; l < c; l++)
						tmp[i*r + k][j*c + l] = a[i][j] * b[k][l];
		memcpy(a, tmp, sizeof a);
		cr *= r, cc *= c;
	}

	int maxi = -INT_MAX, mini = INT_MAX, maxr = -INT_MAX, minr = INT_MAX;
	for (int i = 0; i < cr; i++) {
		int rsum = 0;
		for (int j = 0; j < cc; j++)
			maxi = max(maxi, a[i][j]), mini = min(mini, a[i][j]), rsum += a[i][j];
		maxr = max(maxr, rsum);
		minr = min(minr, rsum);
	}

	int minc = INT_MAX, maxc = -INT_MAX;
	for (int i = 0; i < cc; i++)
	{
		int csum = 0;
		for (int j = 0; j < cr; j++)
			csum += a[j][i];
		minc = min(minc, csum);
		maxc = max(maxc, csum);
	}

	printf("%d\n%d\n%d\n%d\n%d\n%d\n", maxi, mini, maxr, minr, maxc, minc);
	cin >> n;
}