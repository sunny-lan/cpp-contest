#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXT 200010

struct seg {
	int l, r;
	ll lz = 0, maxi = 0;
};

seg t[MAXT * 3];

void apply(ll lz, int i) {
	t[i].lz += lz;
	t[i].maxi += lz;
}

void push_down(int i) {
	apply( t[i].lz, i * 2), apply(t[i].lz, i * 2 + 1 );
	t[i].lz = 0;
}

void push_up(int i) {
	t[i].maxi = max(t[i * 2].maxi, t[i * 2 + 1].maxi);
}

void build(int l, int r, int i = 1) {
	t[i].l = l, t[i].r = r;
	if(l + 1 == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, i * 2), build(mid, r, i * 2 + 1);
}

void update(int l, int r, ll x, int i = 1) {
	if(t[i].r <= r && t[i].l >= l)
	{
		apply(x, i);
		return;
	}
	if(t[i].r <= l || t[i].l >= r)
		return;
	push_down(i);
	update(l, r, x, i * 2), update(l, r, x, i * 2 + 1);
	push_up(i);
}

ll query(int l, int r, int i = 1) {
	if(t[i].r <= r && t[i].l >= l)
		return t[i].maxi;
	if(t[i].r <= l || t[i].l >= r)
		return 0;
	push_down(i);
	return max(query(l, r, i * 2), query(l, r, i * 2 + 1));
}

#define MAXN 100010

vector<int> child[MAXN];
int h[MAXN], v[MAXN], d[MAXN];

int td = 0;
int f[MAXN], l[MAXN];

void dfs(int i = 0, int j = -1) {
	l[i] = f[i] = td++;
	for(int k : child[i])
		if(k != j)
			dfs(k, i),
				l[i] = td++;
}

int ptr[MAXN];
bool pred(int a, int b) {
	return d[a] < d[b];
}
pair<int, pii> qu[MAXN];

ll ans[MAXN];
int p[MAXN];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	stack<int> kust;
	kust.push(0);
	d[0] = h[0] = INT_MAX;
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &h[i], &v[i], &d[i]);
		while( h[kust.top()] <= h[i])
			kust.pop();
		p[i] = kust.top();
		child[kust.top()].push_back(i);
		kust.push(i);
		ptr[i] = i;
	}
	dfs();
	build(0, td);
	for(int i = 0; i < q; i++) {
		int b, m;
		scanf("%d %d", &b, &m);
		qu[i] = {m, {b, i}};
	}
	sort(qu, qu + q);
	sort(ptr, ptr + n + 1, pred);
	int idx = 0;
	for(int i = 0; i < q; i++) {
		while(idx < n && d[ptr[idx]] <= qu[i].f) {
			update(f[ptr[idx]], l[ptr[idx]] + 1, v[ptr[idx]]);
			idx++;
		}
		int b = qu[i].s.f;
		ans[qu[i].s.s] = query(f[b], l[b] + 1) - query(f[p[b]] , f[p[b]]+1);
	}

	for(int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
}
