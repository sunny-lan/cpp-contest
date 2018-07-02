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

int nl;

int p[MAXN];
int f[MAXN][MAXN];

int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({ src , INT_MAX });
	while (!q.empty()) {
		pii i = q.front(); q.pop();
		if (i.first == dst)return i.second;
		for (int j = 0; j < nl; j++)if (f[i.first][j] > 0)
			if (p[j] == -1)
				p[j] = i.first,
				q.push({ j, min(i.second, f[i.first][j]) });
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
			f[par][cur] -= af;
			f[cur][par] += af;
			cur = par;
		}
	}
	return res;
}

int main() {
	int n, m; scan(n); scan(m);
	int src = n + m;
	int dst = n + m + 1;
	for (int i = 0; i < n; i++) {
		if (i != 0)
			f[src][i] = 1;
		int t; scan(t);
		for (int j = 0; j < t; j++) {
			int g; scan(g);
			g += n - 1;
			if (i != 0)
				if (!f[0][g])continue;
			f[i][g] = 1;
		}
	}
	int cnt = 0;
	for (int i = n; i < src; i++)
		if (f[0][i])
			f[i][dst] = 1, cnt++;

	nl = n + m + 2;

	printf("%d\n", cnt - karp(src, dst));
}