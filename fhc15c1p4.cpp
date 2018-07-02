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

#define MAXN 200000

vector<int> children[MAXN];

int dp[19][MAXN];

int f(int i, int p) {
	int &res = dp[p][i];
	if (res != -1)return res;
	int t[] = { 0,0,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0 };
	t[p] = 4521928;
	for (int child : children[i])
		for (int j = 1; j <= 17; j++)if (j != p)
			t[j] += f(child, j);
	res = 4521928;
	for (int j = 1; j <= 17; j++)if (j != p)
		res = min(res, t[j] + j);
	return res;
}

ll _main() {
	memset(dp, -1, sizeof dp);
	int n; scan(n);
	for (int i = 0; i < n; i++)
		children[i] = vector<int>();
	for (int i = 0; i < n; i++)
	{
		int p; scan(p);
		p--;
		if (p >= 0)
			children[p].push_back(i);
	}
	return f(0, 0);
}

int main() {
	int t; scan(t);
	for (int i = 1; i <= t; i++)printf("Case #%d: %lld\n", i, _main());
}