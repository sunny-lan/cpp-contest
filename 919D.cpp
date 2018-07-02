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

#define MAXN 300000

string c;
vector<int> adj[MAXN];
int dp[MAXN];
bool v[MAXN];
bool cyclic(int i) {
	if (dp[i] != -1)
		return dp[i];
	if (v[i])return true;
	v[i] = true;
	bool ans = false;
	for (int j : adj[i])
		ans |= cyclic(j);
	v[i] = false;
	return dp[i] = ans;
}

char filter;
int f(int i) {
	if (dp[i] != -1)return dp[i];
	int res = 0;
	for (int j : adj[i])
		res = max(res, f(j));
	if (c[i] == filter)res++;
	return dp[i] = res;
}

int main() {
	int n, m; scan(n); scan(m);
	cin >> c;
	for (int i = 0; i < m; i++) {
		int x, y; scan(x); scan(y);
		x--, y--;
		adj[x].push_back(y);
	}

	memset(dp, -1, sizeof dp);
	bool ans = false;
	for (int i = 0; i < n; i++)
		ans |= cyclic(i);
	if (ans) {
		printf("-1");
		return 0;
	}

	int res = 0;
	for (filter = 'a'; filter <= 'z'; filter++) {
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++)
			res = max(res, f(i));
	}

	printf("%d", res);

	cin >> n;
}