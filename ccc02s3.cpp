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
int r, c, m;
char ins[30000];
string map[375];

unordered_map<int, bool> dp;

int enc(int d, int i, int x, int y) {
	return d + i * 4 + x * 4 * m + y * 4 * m * c;
}

bool f(int d, int i, int x, int y) {
	if (x < 0 || x >= c || y < 0 || y >= r)return false;
	if (i == m)return 0;
	int st = enc(d, i, x, y);
	if (dp.find(st) != dp.end())return dp[st];
	bool res;
	if (ins[i] == 'F') {
		if (d == 0)res = f(d, i + 1, x + 1, y);
		if (d == 1)res = f(d, i + 1, x, y + 1);
		if (d == 2)res = f(d, i + 1, x - 1, y);
		if (d == 3)res = f(d, i + 1, x, y + 1);
	}
	else if (ins[i] == 'L') {
		res = f((d - 1 + 4) % 4, i + 1, x, y);
	}
	else {
		res = f((d + 1) % 4, i + 1, x, y);
	}
	return dp[st] = res;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)cin >> map[i];
	cin >> m;
	for (int i = 0; i < m; i++)cin >> ins[i];
	
}