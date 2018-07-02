#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 500

int idx = 0;
int adj[MAXN][MAXN];
int p[MAXN];
int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({src, MAXN});
	while(!q.empty()) {
		pii cur = q.front();
		q.pop();
		if(cur.first == dst)
			return cur.second;
		for(int i = 0; i < idx; i++)
			if(adj[cur.first][i] > 0)
				if(p[i] == -1)
					p[i] = cur.first,
						   q.push({i, min(cur.second, adj[cur.first][i])});
	}
	return -1;
}

int mxflow(int src, int dst) {
	int flow = 0;
	while(true) {
		int aug = bfs(src, dst);
		if(aug <= 0)
			break;
		flow += aug;
		int cur = dst;
		while(cur != src) {
			int par = p[cur];
			adj[par][cur] -= aug;
			adj[cur][par] += aug;
			cur = par;
		}
	}
	return flow;
}

unordered_map<int, int> children, categories, toys;

bool cancer[MAXN];

int main() {
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	int src = idx++, dst = idx++;
	for(int i = 0; i < m; i++)
		toys[i]=idx++;
	for(int j = 0; j < n; j++) {
		children[j]=idx++;
		adj[children[j]][dst] = 1;
		int k;
		scanf("%d", &k);
		for(int l = 0; l < k; l++) {
			int i;
			scanf("%d", &i);
			i--;
			adj[toys[i]][children[j]] = 1;
		}
	}
	for(int i = 0; i < p; i++) {
		categories[i]=idx++;
		int l;
		scanf("%d", &l);
		for(int j = 0; j < l; j++) {
			int t;
			scanf("%d", &t);
			t--;
			adj[categories[i]][toys[t]] = 1;
			cancer[t] = true;
		}
		scanf("%d", &adj[src][categories[i]]);
	}

	for(int i = 0; i < m; i++)
		if(!cancer[i])
			adj[src][toys[i]] = 1;

	printf("%d\n", mxflow(src, dst));
}
