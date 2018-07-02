#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200005

ll bit[MAXN];
void update(int p, ll v) {
	for(p++; p < MAXN; p += p & -p)
		bit[p] += v;
}

ll query(int p) {
	ll res = 0;
	for(p++; p > 0; p -= p & -p)
		res += bit[p];
	return res;
}

ll s, t;
ll cst(ll a1, ll a2) {
	if(a1 < a2)
		return s * (a1 - a2);
	else
		return t * (a1 - a2);
}

int main() {
	int n, q;
	scanf("%d%d%lld%lld", &n, &q, &s, &t);
	ll tot = 0;
	ll lst = 0;
	for(int i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		update(i, a), update(i + 1, -a);
		tot += cst(lst, a);
		lst = a;
	}

	for(int i = 0; i < q; i++) {
		int l, r;
		ll x;
		scanf("%d%d%lld", &l, &r, &x);
		r++;
		ll l1 = query(l - 1), l2 = query(l),
		   r1 = query(r - 1), r2 = query(r);
		tot -= cst(l1, l2) + cst(r1, r2);
		update(l, x), update(r, -x);
		tot += cst(l1, l2 + x) + cst(r1 + x, r2);
		printf("%lld\n", tot);
	}
}
