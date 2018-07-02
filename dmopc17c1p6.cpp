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

#define MAXN 1001

int n, q;
int adj[MAXN][MAXN];

int dfs(int i, int j, int k) {
	if (i == k)return 0;
	for (int l = 0; l < n; l++)
		if (l != j && adj[i][l] != -1)
		{
			int res = dfs(l, i, k);
			if (res != -1)
				return res^adj[i][l];
		}
	return -1;
}

int main() {
	memset(adj, -1, sizeof adj);
	scan(n); scan(q);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		a--, b--;
		adj[a][b] = c;
		adj[b][a] = c;
	}

	for (int i = 0; i < q; i++) {
		char op; int x, y; scanf(" %c %d %d", &op, &x, &y);
		x--, y--;
		if (op == 'A') {
			int z; scan(z);
			adj[x][y] = z;
			adj[y][x] = z;
		}
		else if (op == 'R') {
			adj[x][y] = -1;
			adj[y][x] = -1;
		}
		else if (op == 'Q') {
			printf("%d\n", dfs(x, -1, y));
		}
	}

	cin >> n;
}