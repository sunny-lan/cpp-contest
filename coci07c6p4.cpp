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
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000

int t[MAXN][MAXN];
int adj[MAXN][MAXN];
bool inq[MAXN];
int du[MAXN];

int main() {
	memset(adj, -1, sizeof adj);
	memset(t, 0x80, sizeof t);
	memset(du, 0x3f, sizeof du);
	int n, m, a, b, k, g; scan(n); scan(m);
	scan(a); scan(b); scan(k); scan(g);
	a--, b--;
	vector<int> tr;
	for (int i = 0; i < g; i++) {
		int x; scan(x);
		tr.push_back(--x);
	}
	for (int i = 0; i < m; i++) {
		int a, b, l; scan(a); scan(b); scan(l);
		a--, b--;
		adj[a][b] = adj[b][a] = l;
	}
	int prev = -1;
	int tot = -k;
	for (int i : tr) {
		if (prev != -1)
			t[i][prev] = t[prev][i] = tot,
			tot += adj[i][prev];
		prev = i;
	}
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0,a});
	du[a] = 0;
	while (!q.empty()) {
		int i = q.top().second; q.pop();
		inq[i] = false;
		int dis = du[i];
		for (int j = 0; j < n;j++)if(adj[i][j]!=-1) {
			int alt;
			if (dis >= t[i][j] && dis < t[i][j] + adj[i][j])
				alt = t[i][j] + 2 * adj[i][j];
			else
				alt = dis + adj[i][j];
			if (alt < du[j]) {
				du[j] = alt;
				if (!inq[j]) {
					inq[j] = true;
					q.push({alt, j});
				}
			}
		}
	}
	printf("%d\n", du[b]);
	cin >> b;
}