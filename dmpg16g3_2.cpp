#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

#define MAXN 100000
#define MAXE 200000

ll bit[MAXE];
void b_upd(int p, ll v) {
	if(p == -1)
		return;
	p++;
	for(int i = p; i < MAXE; i += i & -i)
		bit[i] += v;
}
ll b_qry(int p) {
	p++;
	ll res = 0;
	for(int i = p; i > 0; i -= i & -i)
		res += bit[i];
	return res;
}

int p[MAXN];
int f(int x) {
	if(p[x] == x)
		return x;
	return p[x] = f(p[x]);
}

vector<int> adj[MAXN];
int h[MAXN], par[MAXN], sz[MAXN], disc[MAXN];
ll tans[MAXN];
unordered_map<int, int> edsc[MAXN];
int ct = 0;
void init(int i = 0, int j = 0) {
	disc[i] = ct++, par[i] = j, p[i] = i, sz[i] = 1;
	for(int k : adj[i])
		if(k != j) {
			edsc[i][k] = ct;
			h[k] = h[i] + 1, init(k, i), sz[i] += sz[k], tans[i] += tans[k] + sz[k];
			edsc[k][i] = ct++;
		}
}

ll ans[MAXN];
void dfs(int i = 0, int j = -1) {
	if(i == 0)
		ans[i] = tans[i];
	else
		ans[i] = tans[i] + (ans[j] - (tans[i] + sz[i])) + (sz[0] - sz[i]);
	b_upd(disc[i], ans[i]), b_upd(disc[i] + 1, -ans[i]);
	for(int k : adj[i])
		if(k != j)
			dfs(k, i);
}

void upd(int a, int p) {
	if(disc[a] > disc[p])
		swap(a, p);
	int sp = sz[p], sa = (sz[0] - sz[p]);
	b_upd(0, -sp), b_upd(edsc[a][p], -sa + sp), b_upd(edsc[p][a], -sp + sa);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	init(), dfs();
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int op, a;
		scanf("%d %d", &op, &a);
		a--;
		if(op == 1) {
			int b;
			scanf("%d", &b);
			b--;
			while((a = f(a)) != (b = f(b))) {
				if(h[a] > h[b])
					upd(a, par[a]), p[a] = f(par[a]), a = par[a];
				else
					upd(b, par[b]), p[b] = f(par[b]), b = par[b];
			}
		} else
			printf("%lld\n", b_qry(disc[a]));
	}
}
