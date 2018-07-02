#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <bitset>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 300

int n;
bitset<MAXN*MAXN> adj[MAXN*MAXN];

int p[MAXN*MAXN];

int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({ src , INT_MAX });
	while (!q.empty()) {
		pii i = q.front(); q.pop();
		if (i.second == 0)continue;
		if (i.first == dst)return i.second;
		for (int j = 0; j < n; j++)if (adj[i.first][j])
			if (p[j] == -1)
				p[j] = i.first,
				q.push({ j, 1 });
	}
	return -1;
}

int karp(int src, int dst) {
	int res = 0;
	while (true) {
		int af = bfs(src, dst);
		if (af <= 0)break;
		res += af;
		int cur = dst;
		while (cur != src) {
			int par = p[cur];
			adj[par][cur] = false;
			adj[cur][par] = true;
			cur = par;
		}
	}
	return res;
}

int st, ed;
int mp[MAXN][MAXN];

void mk(int l, int m, int i, int j) {
	if (l == -2) {
		adj[st][2 * (i*n + j)] = true;
		return;
	}
	if (i < 0 || j < 0 || i >= n || j >= n)return;
	if (mp[l][m] == 3) {
		adj[2 * (l*n + m) + 1][ed] = true;
		return;
	}
	if (mp[i][j] != mp[l][m] + 1)return;
	adj[2 * (l*n + m) + 1][2 * (i*n + j)] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	st = 2 * (n*n) + 2, ed = 2 * (n*n) + 3;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == 'C')
				mp[i][j] = 0;
			else if (s[j] == 'A')
				mp[i][j] = 1;
			else if (s[j] == 'L')
				mp[i][j] = 2;
			else if (s[j] == 'I')
				mp[i][j] = 3;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			adj[2 * (i*n + j)][2 * (i*n + j) + 1] = 1;
			if (mp[i][j] == 0)
				mk(-2, 0, i, j);
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			mk(i, j, i + 1, j);
			mk(i, j, i - 1, j);
			mk(i, j, i, j + 1);
			mk(i, j, i, j - 1);
			mk(i, j, i + 1, j + 1);
			mk(i, j, i - 1, j - 1);
			mk(i, j, i + 1, j - 1);
			mk(i, j, i - 1, j + 1);
		}
	n = max(st, ed) + 1;
	printf("%d\n", karp(st, ed));

	cin >> n;
}