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

int height, width, a, b, c;

int cancer(int v, int x, int y, bool g) {
	if (g)
		return v | (1 << (x*width + y));
	else
		return v & ~(1 << (x*width + y));
}

bool get(int v, int x, int y) {
	return (v >> (x*width + y)) & 1;
}

int nxt(int v) {
	int res = 0;
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++) {
			int adj = 0;
			adj += get(v, x + 1, y);

			if (x > 0)adj += get(v, x - 1, y);
			adj += get(v, x, y + 1);
			if (y > 0)adj += get(v, x, y - 1);

			if (x > 0)if (y > 0)adj += get(v, x - 1, y - 1);
			if (x > 0)adj += get(v, x - 1, y + 1);
			if (y > 0)adj += get(v, x + 1, y - 1);
			adj += get(v, x + 1, y + 1);

			bool stat = get(v, x, y);

			if (stat && adj < a)continue;
			if (stat && adj > b)continue;
			if (!stat && adj > c)
				res = cancer(res, x, y, true);
			else
				res = cancer(res, x, y, stat);
		}
	return res;
}

#define MAXS 16777216

int p[MAXS];
int deg[MAXS];

int dp[MAXS];
int dst;

int f(int i) {
	if (i == dst)return 0;
	int &res = dp[i];
	if (res != -1)return res;
	res = 1 << 30;
	res = f(p[i]) + 1;
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> height >> width >> a >> b >> c;
	for (int y = 0; y < height; y++) {
		string s; cin >> s;
		for (int x = 0; x < width; x++)
			if (s[x] == '*')
				dst = cancer(dst, x, y, true);
	}
	for (int i = 0; i < 1 << (height*width + height); i++)
	{
		p[i] = nxt(i);
		deg[p[i]]++;
	}

	int mini = 1 << 30;
	for (int i = 0; i < 1 << (height*width + height); i++)if (deg[i] == 0)
	{
		mini = min(mini, f(i));
	}

	if (mini >= 1 << 30)
		printf("-1\n");
	else
		printf("%d\n", mini);
}