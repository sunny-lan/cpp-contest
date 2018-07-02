#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200001
#define BS 450

int cnt[BS][MAXN];
int v[MAXN];

int bs;

int query(int l, int r, int x) {
	int sb = (l + bs - 1) / bs,
		eb = r / bs;
	int res = 0;
	for(int i = sb; i < eb; i++)
		res += cnt[i][x];
	for(int i = l; i < sb * bs; i++)
		if(v[i] % x == 0)
			res++;
	for(int i = eb * bs; i < r; i++)
		if(v[i] % x == 0)
			res++;
	return res;
}

void update(int p, int vv, int y) {
	for(ll f = 1; f * f <= vv; f++)
		if(vv % f == 0) {
			cnt[p / bs][f] += y;
			if(vv / f != f)
				cnt[p / bs][vv / f] += y;
		}
}

void update(int p, int vv) {
	if(v[p] != -1)
		update(p, v[p], -1);
	v[p] = vv;
	update(p, vv, 1);
}

int main() {
	memset(v, -1, sizeof v);
	int n, q;
	scanf("%d%d", &n, &q);
	bs=sqrt(n);
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		update(i, a);
	}
	for(int i = 0; i < q; i++) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", query(l - 1, r, x));
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			update(u - 1, v);
		}
	}
}
