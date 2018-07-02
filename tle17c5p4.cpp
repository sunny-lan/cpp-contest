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

#define MAXM 200000
#define L 0
#define H 1
#define X 2
#define NX 3

int n, m;
int child[MAXM][2];
int dp[MAXM][4];

int f(int i, int j) {
	if (i < n) {
		if (j == X)return 0;
		if (j == NX)return -(1 << 30);
		return 1;
	}
	int res = dp[i][j];
	if (res != -1)return res;
	res = -(1 << 30);
	if (j == X) {
		int alt = f(child[i][0], H) + f(child[i][1], NX);
		if (alt > res) {
			res = alt;
		}
		alt = f(child[i][0], NX) + f(child[i][1], H);
		if (alt > res) {
			res = alt;
		}
	}
	if (j == NX) {
		int alt = f(child[i][0], H) + f(child[i][1], X);
		if (alt > res) {
			res = alt;
		}
		alt = f(child[i][0], X) + f(child[i][1], H);
		if (alt > res) {
			res = alt;
		}
	}
	if (j == H) {
		int alt = f(child[i][0], L) + f(child[i][1], H);
		if (alt > res) {
			res = alt;
		}
		alt = f(child[i][0], H) + f(child[i][1], L);
		if (alt > res) {
			res = alt;
		}
		alt = f(child[i][0], L) + f(child[i][1], L);
		if (alt > res) {
			res = alt;
		}
	}
	if (j == L) {
		res = f(child[i][0], H) + f(child[i][1], H);
	}
	return dp[i][j] = max(res, -(1<<30));
}

int main() {
	memset(dp, -1, sizeof dp);
	scan(n); scan(m);
	for (int i = n; i < m+n; i++) {
		scan(child[i ][0]);
		scan(child[i ][1]);
		child[i][0]--; child[i][1]--;
	}
	int r=max(f(m + n - 1, X), f(m + n - 1, NX));
	cin >> n;
}