#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 500

vector<pii> adj[MAXN];
int n, m, w;
int du[MAXN];
bool sp(int src = 0) {
	memset(du, 0x3f, sizeof du);
	for(int it = 0; it < n; it++)
		for(int i = 0; i < n; i++)
			for(pii k : adj[i])
				du[k.f] = min(du[k.f], du[i] + k.s);
	for(int i = 0; i < n; i++)
		for(pii k : adj[i])
			if(du[i] + k.s < du[k.f])
				return true;
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++) {
		scanf("%d%d%d", &n, &m, &w);
		for(int i = 0; i < n; i++)
			adj[i].clear();
		for(int i = 0; i < m; i++)
		{
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);
			a--, b--;
			adj[a].push_back({b, t});
			adj[b].push_back({a, t});
		}
		for(int i = 0; i < w; i++) {
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);
			a--, b--;
			adj[a].push_back({b, -t});
		}
		if(sp())
            printf("YES\n");
        else
            printf("NO\n");
	}
}
