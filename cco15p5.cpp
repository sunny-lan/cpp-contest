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

#define MAXN 110
#define MAXD 4100

pii notes[MAXN];
double dp[MAXN][MAXD][5];

int n, d;

double f(int note, int drum, int sub) {
	if (note == n - 1)return INFINITY;
	double &res = dp[note][drum][sub];
	if (res != -INFINITY)
		return res;
	res = 0;
	if ((drum >> notes[note+1].second) & 1)
		res = max(res, min(f(note + 1, drum, 0), (notes[note + 1].first - notes[note].first) / (double)sub));
	if (sub < d)
		for (int i = 0; i < 12; i++)
			if ((drum >> i) & 1)
			{
				int cpy = drum & ~(1 << i);
				for (int j = i - 1; j >= 0; j--)
				{
					if ((drum >> j) & 1)break;
					res = max(res, f(note, cpy | (1 << j), sub + 1));
				}

				for (int j = i + 1; j < 12; j++)
				{
					if ((drum >> j) & 1)break;
					res = max(res, f(note, cpy | (1 << j), sub + 1));
				}
			}
	return res;
}

int popcnt(int i)
{
	// Java: use >>> instead of >>
	// C or C++: use uint32_t
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}


int main() {
	scan(n); scan(d);
	for (int i = 0; i < n; i++) {
		scan(notes[i].first);
		scan(notes[i].second); notes[i].second--;
		for (int j = 0; j < MAXD; j++)
			for (int k = 0; k <= d; k++)
				dp[i][j][k] = -INFINITY;
	}

	sort(notes, notes + n);

	int first = notes[0].second;

	double res = -INFINITY;

	for (int i = 0; i < MAXD; i++)
		if (popcnt(i) == d)
			if ((i >> first) & 1)
				res = max(res, f(0, i, 0));

	if (res == INFINITY)
		printf("0.00\n");
	else
		printf("%.2lf\n", res);

	cin >> n;
}