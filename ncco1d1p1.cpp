#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 510

int adj[MAXN][MAXN];

int p[MAXN];
int idx=0;

bool bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({ src , INT_MAX });
	while (!q.empty()) {
		pii i = q.front(); q.pop();
		if (i.first == dst)return i.second;
		for (int j = 0; j < idx; j++)if (adj[i.first][j] != 0)
			if (p[j] == -1)
				p[j] = i.first,
				q.push({ j, min(i.second, adj[i.first][j]) });
	}
	return false;
}

int karp(int src, int dst) {
	int res = 0;
	while (true) {
            int af=bfs(src, dst);
    if(af<=0 )break;
		res+=af;
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

int x[MAXN], y[MAXN];
int cn[MAXN];

int main() {
	int l, w, n;
	scanf("%d %d %d", &l, &w, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		cn[i] = idx;
        adj[idx][idx+1]=1;
        adj[idx+1][idx]=1;
		idx+=2;
	}
	int src = idx++, dst = idx++;
	for(int i=0;i<n;i++){
		for(int j = i+1; j < n; j++)
		{
			double dx = x[i] - x[j],
				dy = y[i] - y[j];
			if(sqrt(dx * dx + dy * dy) <= 200.000001){
				adj[cn[i]+1][cn[j]]=1;
				adj[cn[j]+1][cn[i]]=1;
			}
		}
		if(y[i]   <= 100)
			adj[src][cn[i]]=adj[cn[i]+1][src]=1;
		if(y[i] + 100 >= w)
			adj[cn[i]+1][dst]=adj[dst][cn[i]]=1;
	}
	printf("%d\n", karp(src, dst));
}
