#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 200000
#define f first
#define s second

int bit[MAXN];
void update(int p, int v) {
	for(p++; p < MAXN; p += p & -p)
		bit[p] += v;
}

int query(int p) {
	int res = 0;
	for(p++; p > 0; p -= p & -p)
		res += bit[p];
	return res;
}

string type;
vector<int> adj[MAXN];

int sz[MAXN];
bool v[MAXN];

int cfs(int i, int j = -1) {
	sz[i] = 1;
	for(int k : adj[i])
		if(!v[k] && k != j)
			sz[i] += cfs(k, i);
	return sz[i];
}

inline int centroid(int i, int tsz, int j = -1) {
	for(int k : adj[i])
		if(k != j && !v[k] && sz[k] * 2 > tsz)
			return centroid(k, tsz, i);
	return i;
}

vector<pii> pts;
ll res1 = 0;
int n, lk, rk, lc, rc, koff, coff;

void dfs(int i, int j = -1, int ki = 0, int cr = 0) {
	if(v[i])
		return;
	if(type[i] == 'K')
		ki++;
	else
		cr++;
	pts.push_back({ki, cr});
	for(int k : adj[i])
		if(k != j)
			dfs(k, i, ki, cr);
}

void calc(int i) {
	i = centroid(i, cfs(i));
	v[i] = true;
	koff = type[i] == 'K' ? 1 : 0,
	coff = type[i] == 'C' ? 1 : 0;
	vector<pii> all;
	for(int k : adj[i]) {
		if(v[k])
			continue;
		pts.clear();
		dfs(k, i, koff, coff);

		sort(pts.begin(), pts.end());
		int glk = pts.size() - 1, grk = glk;
		for(int j = 0; j < pts.size(); j++) {
//			if(glk < j) {
//				glk++;
//				for(; glk <= min(grk, j); glk++)
//					update(pts[glk].s, -1);
//				glk--;
//			}
			pii val = pts[j];
			while(glk > j && val.f + pts[glk].f - koff >= lk)
				update(pts[glk].s, 1), glk--;
			while(grk > glk && val.f + pts[grk].f - koff > rk)
				update(pts[grk].s, -1), grk--;
			res1 -= query(rc - val.s + coff) - query(lc - val.s + coff - 1);
			all.push_back(pts[j]);
		}
	}
	if(koff >= lk && koff <= rk && coff >= lc && coff <= rc)
		res1++;
	all.push_back({0, 0});
	sort(all.begin(), all.end());
	int glk = all.size() - 1, grk = glk;
	for(int j = 0; j < all.size(); j++) {
//		if(glk < j) {
//			glk++;
//			for(; glk <= min(grk, j); glk++)
//				update(all[glk].s, -1);
//			glk--;
//		}
		pii val = all[j];
		int toff;
		if(val.f == 0 && val.s == 0)
			toff = 0;
		else
			toff = 1;
		while(glk > j && val.f + all[glk].f - koff * toff >= lk)
			update(all[glk].s, 1), glk--;
		while(grk > glk && val.f + all[grk].f - koff * toff > rk)
			update(all[grk].s, -1), grk--;
		res1 += query(rc - val.s + coff * toff) - query(lc - val.s + coff * toff - 1);
	}

	for(int k : adj[i])
		if(!v[k])
			calc(k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> lk >> rk >> lc >> rc >> type;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	calc(0);
	printf("%lld\n", res1);
}
