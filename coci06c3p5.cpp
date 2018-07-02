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

#define MAXN 10010
#define MOD 1000000000ll

vector<int> adj[MAXN];

pair<ll, pair<bool, bool>> dp[MAXN];
bool v[MAXN];

pair<ll, pair<bool, bool>> f(int i) {
	if (i == 1) return{ 1,{false,false} };
	if (v[i])return{ 0,{false,true} };
	pair<ll, pair<bool, bool>> res = dp[i];
	if (res.first != -1)return res;
	res = { 0,{false,false} };
	v[i] = true;
	for (int j : adj[i]) {
		pair<ll, pair<bool, bool>> alt = f(j);

		if (res.first + alt.first >= MOD)
			res.second.first = true;
		res.first += alt.first;
		res.second.first |= alt.second.first;
		res.second.second |= alt.second.second;
		res.first %= MOD;
	}
	v[i] = false;
	if (res.first == 0)res.second.second = false;
	return dp[i] = res;
}

int main() {
	memset(dp, -1, sizeof dp);
	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b; scan(a); scan(b);
		adj[--a].push_back(--b);
	}
	pair<ll, pair<bool, bool>> res = f(0);
	if (res.second.second)
		printf("inf\n");
	else
	{
		if (res.second.first)
			for (int i = 0; i < 8 - (int)log10(res.first); i++)
				printf("0");
		printf("%lld\n", res.first);
	}
}