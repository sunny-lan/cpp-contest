#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXB 18

vector<int> adj[MAXN];
unordered_map<int, int> sd[MAXN];
vector<int> nd[MAXN];

void ins(int a, int b, int c) {
	if(a > b)
		swap(a, b);
	if(sd[a].count(b) == 0) {
		sd[a][b] = c;
		return;
	}
	int d = sd[a][b];
	adj[c].push_back(d);
	adj[d].push_back(c);
}

vector<int> tour;
int pre[MAXN], h[MAXN];
void init(int i = 0, int j = -1) {
	pre[i] = tour.size();
	tour.push_back(i);
	for(int k : adj[i])
		if(k != j)
			h[k] = h[i] + 1, init(k, i),
	tour.push_back(i);
}

int pred(int a, int b) {
	return h[a] < h[b] ? a : b;
}

int sp[MAXB][MAXN*2];
void cons() {
	int n = tour.size();
	for(int i = 0; i < n; i++)
		sp[0][i] = tour[i];
	for(int lvl = 1, bs = 2; bs <= n; lvl++, bs <<= 1)
		for(int i = 0; i + bs <= n; i++)
			sp[lvl][i] = pred(sp[lvl - 1][i], sp[lvl - 1][i + bs / 2]);
}

int cb(int x) {
	int res = 0;
	while(x = (x >> 1))
		res++;
	return res;
}

int qq(int l, int r) {
	int lvl = cb(r - l);
	return pred(sp[lvl][l], sp[lvl][r - (1 << lvl)]);
}

int lca(int a, int b) {
	if(pre[a] > pre[b])
		swap(a, b);
	return qq(pre[a], pre[b] + 1);
}

int dif[MAXN];
int ans = 0;
int dfs(int i = 0, int j = -1) {
	int tot = dif[i];
	for(int k : adj[i])
		if(k != j) {
			int alt = dfs(k, i);
			if(alt == 0)
				ans++;
			tot += alt;
		}
	return tot;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 2; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		nd[d].push_back(i);
		ins(a, b, i), ins(b, c, i), ins(c, a, i);
	}
	init();
	cons();
	for(int i = 1; i <= n; i++) {
		int tl = -1;
		for(int j : nd[i]) {
			dif[j]++;
			if(tl == -1)
				tl = j;
			else
				tl = lca(tl, j);
		}
		if(tl != -1)
			dif[tl] -= nd[i].size();
	}
	dfs();
    printf("%d\n", ans);
}
