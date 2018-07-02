#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 100

vector<int> adj[MAXN];

int blk;

bool v[MAXN];
pii e[MAXN*MAXN];
void dfs(int i) {
	if (v[i])return;
	v[i] = true;
	for (int j : adj[i]) 
		if (i != e[blk].first || j!=e[blk].second)
			dfs(j);
}


int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int s, t; scanf("%d %d", &s, &t);
		s--, t--;
		adj[s].push_back(t);
		e[i] = { s,t };
	}

	for (blk = 0; blk < m; blk++)
	{
		memset(v, false, sizeof v);
		dfs(0);
		if (v[n - 1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	cin >> n;
}