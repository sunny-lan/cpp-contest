#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100000
#define MAXQ 200000

void bit_upd(int p, int v, int bit[MAXQ]) {
	if(p == -1)
		return;
	p++;
	for(int i = p; i < MAXQ; i += i & -i)
		bit[i] += v;
}

int bit_qry(int p, int bit[]) {
	p++;
	int res = 0;
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

int h[MAXN], par[MAXN];
void init(int i = 0, int j = 0) {
	par[i] = j;
	p[i] = i;
	for(int k : adj[i])
		if(k != j)
			h[k] = h[i] + 1, init(k, i);
}

struct qry {
	int t, op, a, d = -1, ans = -1;
};
vector<qry> qrys;
vector<int> tqrys[MAXN];
int updt[MAXN];

int bit_dst[MAXQ], bit_ans[MAXQ];
int sz[MAXN], ssz[MAXN], sans[MAXN], sub[MAXN];
int cs;

int dfs(int i = 0, int j = -1) {
	bit_upd(updt[i], 1, bit_dst);

	if(j == 0)
		cs = i;

	sz[i] = 1;
	int res = 0;
	for(int k : adj[i])
		if(k != j) {
			int alt = dfs(k, i);
			alt += sz[k];
			res += alt, sz[i] += sz[k];
			if(i == 0)
				sans[k] = alt;
		}

	bit_upd(updt[i], -1, bit_dst);

	for(int k : tqrys[i])
		qrys[k].ans = res - bit_qry(qrys[k].t, bit_ans), qrys[k].d = h[i] - bit_qry(qrys[k].t, bit_dst);

	bit_upd(updt[i], sz[i], bit_ans);

	if(i == 0)
		sub[0] = 0, ssz[0] = sz[0], sans[0] = res;
	else
		sub[i] = cs, ssz[cs]++;

	return res;
}

int main() {
	memset(updt, -1, sizeof updt);

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	init();

	int q;
	scanf("%d", &q);
	int qidx = 0;
	for(int i = 0; i < q; i++) {
		int op, a;
		scanf("%d %d", &op, &a);
		a--;
		if(op == 1) {
			int b;
			scanf("%d", &b);
			b--;
			while((a = f(a)) != (b = f(b))) {
				if(h[a] > h[b]) {
					updt[a] = qidx++;
					qrys.push_back({qidx, 2, a});
					p[a] = f(par[a]);
					a = par[a];
				} else {
					updt[b] = qidx++;
					qrys.push_back({qidx, 2, b});
					p[b] = f(par[b]);
					a = par[b];
				}
			}
		} else {
			qrys.push_back({qidx, 1, a});
			tqrys[a].push_back(qidx++);
		}
	}

	int rtans = dfs();
//	cout <<rtans<<endl;
	for(qry q : qrys)
		if(q.op == 1)
//			printf("%d\n", q.d),
				   printf("%d\n", q.ans + (rtans - bit_qry(q.t, bit_ans) ) - sans[sub[q.a]] + (sz[0] - ssz[sub[q.a]])*q.d);
		else
			sans[sub[q.a]] -= sub[q.a];
}
