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

#define MAXN 3000

int c[MAXN];

vector<int> adj[MAXN];

vector<int> path;

bool dfs(int i, int j, int d) {
	if (i == d) {
		path.push_back(c[d]);
		return true;
	}
	bool cust = false;
	for (int neigh : adj[i])
		if (neigh != j)
			cust |= dfs(neigh, i, d);
	if (cust)
		path.push_back(c[i]);
	return cust;
}

int main() {
	int n, q; scan(n); scan(q);
	for (int i = 0; i < n; i++) scan(c[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < q; i++) {
		int u, v; scan(u); scan(v);
		u--, v--;
		path = vector<int>();
		dfs(u, -1, v);
		sort(path.begin(), path.end());
		int mini = INT_MAX;
		int prev = -1;
		for (int c : path) {
			if (prev != -1)
				mini = min(mini, abs(c - prev));
			prev = c;
		}
		printf("%d\n", mini);
	}

	cin >> n;
}