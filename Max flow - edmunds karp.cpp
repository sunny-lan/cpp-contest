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

#define MAXN 500

int n;
int adj[MAXN][MAXN];

int p[MAXN];

int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({ src , INT_MAX });
	while (!q.empty()) {
		pii i = q.front(); q.pop();
		if (i.first == dst)return i.second;
		for (int j = 0; j < n; j++)if (adj[i.first][j] > 0)
			if (p[j] == -1)
				p[j] = i.first,
				q.push({ j, min(i.second, adj[i.first][j]) });
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
			adj[par][cur] -= af;
			adj[cur][par] += af;
			cur = par;
		}
	}
	return res;
}

int main() {
	int  m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		adj[a][b] += c;
	}
	int s, d; scan(s); scan(d);
	printf("%d\n", karp(s, d));
	cin >> m;
}