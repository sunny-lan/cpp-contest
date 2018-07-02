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
typedef long long ll;

//template variables
#define MAXN 2010
int n=2005, m=2005;
int value[MAXN][MAXN];

//template starts here
int prefix[MAXN + 1][MAXN + 1];

//GUD CONTENT:
//sum for rectangle prism in any dimension
//let (a1,a2,...,an) be the first point
//let (b1,b2,...,bn) be the second point (should have larger coordinates)
//answer should be sum of psa(...) for all combinations of a and b for each dimension
//each term of sum can either have positive sign or negative sign.
//if it has odd number of dimesions in b, sign is negative
//if it has even number, sign is positive

inline int sum(int x, int y, int x2, int y2) {
	int whole = prefix[y2][x2];
	int lcol = prefix[y][x2];
	int minsqr = prefix[y][x];
	int ucol = prefix[y2][x];
	return whole - ((lcol + ucol) - minsqr);
}

void construct() {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			prefix[i][j] = prefix[i - 1][j] + value[i - 1][j - 1];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			prefix[i][j] += prefix[i][j - 1];
}
//template ends here

vector<pair<int, int>> pts;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		int p, q, r, s;
		scanf("%d %d %d %d", &p, &q, &r, &s);
		pts.push_back({ p,q });
		pts.push_back({ r,s });
		pts.push_back({ p,s });
		pts.push_back({ r,q });
		prefix[p][q]++;
		prefix[p][s]--;
		prefix[r][q]--;
		prefix[r][s]++;
	}

	construct();

	int res = 0;
	for (auto pt : pts) {
		int cnt = 0;
		if(prefix[])
	}

	printf("%d", res);
	cin >> res;
}
