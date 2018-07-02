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

#define MAXN 100

bool adj[MAXN][MAXN];
bool visited[MAXN];
int n, m;

void f(int i) {
	if (visited[i])return;
	visited[i] = true;
	for (int neigh = 0; neigh < n; neigh++)
		if (adj[i][neigh]) {
			f(neigh);
		}
}

pii edge[MAXN];

int main() {
	for (int t = 0; t < 5; t++) {
		memset(adj, false, sizeof adj);
		scan(n); scan(m);
		for (int i = 0; i < m; i++) {
			int a, b; scan(a); scan(b);
			a--, b--;
			adj[a][b] = adj[b][a] = true;
			edge[i] = { a,b };
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			memset(visited, false, sizeof visited);
			pii e = edge[i];
			adj[e.first][e.second] = adj[e.second][e.first] = false;
			f(0);
			adj[e.first][e.second] = adj[e.second][e.first] = true;
			for (int j = 0; j < n; j++)
				if (!visited[j]) {
					cnt++;
					break;
				}
		}
		printf("%d\n", cnt);
	}
}