#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

unordered_set<int> adj[MAXN];

set<int> cheese;

void dfs(int i) {
	cheese.erase(i);
	for(int j : cheese)
		if(adj[i].count(j) == 0)
			dfs(j);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		adj[x].insert(y);
		adj[y].insert(x);
	}

	for(int i = 0; i < n; i++)
        cheese.insert(i);

	int cnt = 0;

	for(int i = 0; i < n; i++)
		if(cheese.count(i) > 0)
			cnt++, dfs(i);

	printf("%d", cnt);
}
