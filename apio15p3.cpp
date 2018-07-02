#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define f first
#define s second

struct node {
	node *l = nullptr, *r = nullptr;
	ll v;
	int p, sz, cnt;
	node(ll _v) {
		v = _v, cnt = sz = 1, p = rand();
	}
};
inline int sz(node *t) {
	return t ? t->sz : 0;
}
inline void push_up(node *t) {
	t->sz = t->cnt + sz(t->l) + sz(t->r);
}
inline node* rotl(node *x) {
	node *y = x->r, *a = y->l;
	y->l = x, x->r = a;
	push_up(x), push_up(y);
	return y;
}
inline node* rotr(node *y) {
	node *x = y->l, *a = x->r;
	x->r = y, y->l = a;
	push_up(y), push_up(x);
	return x;
}
inline node* ins(ll v, node *t) {
	if(!t)
		return new node(v);
	if(v < t->v) {
		if((t->l = ins(v, t->l))->p > t->p)
			t = rotr(t);
	} else if(v > t->v) {
		if((t->r = ins(v, t->r))->p > t->p)
			t = rotl(t);
	} else
		t->cnt++;
	push_up(t);
	return t;
}
inline node* del(node* x) {
	if (x->l && x->r) {
		if(x->l->p < x->r->p)
			x = rotl(x), x->l = del(x->l);
		else
			x = rotr(x), x->r = del(x->r);
		push_up(x);
		return x;
	}
	node* replace = nullptr;
	if (x->l) replace = x->l;
	if (x->r) replace = x->r;
	delete x;
	return replace;
}
inline node* del(ll v, node* t) {
	if (!t)
		return t;
	if (v == t->v) {
		if (--t->cnt == 0)
			return del(t);
	}
	else {
		if (v < t->v)
			t->l = del(v, t->l);
		else
			t->r = del(v, t->r);
	}
	push_up(t);
	return t;
}
inline node* kth(int k, node *t) {
	if(k < sz(t->l))
		return kth(k, t->l);
	if(k >= sz(t->l) + t->cnt)
		return kth(k - (sz(t->l) + t->cnt), t->r);
	return t;
}
inline int l_b(ll v, node *t) { //finds first >=
	if(!t)
		return 0;
	if(v < t->v)
		return l_b(v, t->l);
	if(v > t->v)
		return l_b(v, t->r) + sz(t->l) + t->cnt;
	return sz(t->l);
}
inline int u_b(ll v, node *t) { //finds first >
	if(!t)
		return 0;
	if(v < t->v)
		return u_b(v, t->l);
	if(v >= t->v)
		return u_b(v, t->r) + sz(t->l) + t->cnt;
	return sz(t->l);
}

vector<pll> cs;
pdd fbest(int st, int ed) {
	if(st >= ed)
		return {0, -1};
	vector<ll> pts;
	for(int i = st; i < ed; i++)
		pts.push_back(cs[i].f), pts.push_back(cs[i].s);
	sort(pts.begin(), pts.end());
	int md = pts.size() / 2;
	double kust = (pts[md] + pts[md - 1]) / 2.0, tot = 0;
	for(ll x : pts)
		tot += abs(x - kust);
	return {tot, kust};
}

bool pred(pll a, pll b) {
	return (a.f + a.s) / 2.0 < (b.f + b.s) / 2.0;
}

ll alg2() {
	node *l = nullptr, *r = nullptr;
	for(int i = 1; i < cs.size(); i++)
		r = ins(cs[i].f, ins(cs[i].s, r));
	l = ins(cs.front().f, ins(cs.front().s, l));
	pdd lol = fbest(1, cs.size());
	double cl = abs(cs.front().s - cs.front().f), cr = lol.f;
	double ml = (cs.front().f + cs.front().s) / 2.0, mr = lol.s;
	double mini = fbest(0, cs.size()).f;
	for(int mid = 1; mid < cs.size(); mid++) {
		mini = min(mini, cl + cr);
		if(r) {
			r = del(cs[mid].f, del(cs[mid].s, r));
			if(r) {
				cr -= abs(mr - cs[mid].f), cr -= abs(mr - cs[mid].s);
				int md = sz(r) / 2;
				double nmr = (kth(md, r)->v + kth(md - 1, r)->v) / 2.0;
				int a = u_b((ll)mr, r), b = l_b((ll)ceil(nmr), r);
				cr += a * abs(mr - nmr);
				cr -= (sz(r) - b) * abs(mr - nmr);
				if(a < b) {
					ll od = kth(a, r)->v;
					cr -= abs(od - mr), cr += abs(od - nmr);
				}
				mr = nmr;
			}
		}
		cl += abs(ml - cs[mid].f), cl += abs(ml - cs[mid].s);
		l = ins(cs[mid].f, ins(cs[mid].s, l));
		int md = sz(l) / 2;
		double nml = (kth(md, l)->v + kth(md - 1, l)->v) / 2.0;
		int a = u_b((ll)ml, l), b = l_b((ll)ceil(nml), l);
		cl += a * abs(ml - nml);
		cl -= (sz(l) - b) * abs(ml - nml);
		if(a < b) {
			ll od = kth(a, l)->v;
			cl -= abs(od - ml), cl += abs(od - nml);
		}
		ml = nml;
	}
	return (ll)mini;
}

int main() {
//	freopen("C:\\Users\\sunny\\Desktop\\kms.txt", "r", stdin);
	srand(time(0));
	int k, n;
	scanf("%d %d", &k, &n);
	cs.clear();
	ll tot = 0;
	for(int i = 0; i < n; i++) {
		char p, q;
		ll s, t;
		scanf(" %c %lld %c %lld", &p, &s, &q, &t);
		if(p == q)
			tot += abs(s - t);
		else {
			tot++;
			cs.push_back({s, t});
		}
	}
	if(cs.empty())
		printf("%lld", tot);
	else if(k == 1) {
		printf("%lld", (ll)fbest(0, cs.size()).f + tot);
	} else {
		sort(cs.begin(), cs.end(), pred);
		printf("%lld\n", alg2() + tot);
	}
}
