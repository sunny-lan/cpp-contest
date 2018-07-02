#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 6000

vector<pair<int, unsigned int>> adj[MAXN];

unsigned int pre[MAXN][MAXN];
int src;

void dfs(int i, int j, unsigned int d) {
	pre[src][i] = d;
	for (auto neigh : adj[i]) {
		if (neigh.first == j)continue;
		dfs(neigh.first, i, d + neigh.second);
	}
}

int main() {
	int n;
	scan(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		unsigned int w;
		scan(a);
		scan(b);
		scan(w);
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });
	}

	for (int i = 0; i < n; i++) {
		src = i;
		dfs(src, -1, 0u);
	}

	int q;
	scan(q);
	for (int i = 0; i < q; i++) {
		int u, v;
		scan(u);
		scan(v);
		printf("%u\n", pre[u][v]);
	}
}