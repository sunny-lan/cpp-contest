#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	node *l = nullptr, *r = nullptr;
	int p, sz, cnt;
	ll v, sm, lz = 0;
	node(ll _v, int _cnt = 1) {
		p = rand(), sm = v = _v, cnt = sz = _cnt;
	}
};
int sz(node *t) {
	return t ? t->sz : 0;
}
ll sm(node *t) {
	return t ? t->sm : 0;
}
void apply(ll lz, node *t) {
	if(!t)
		return;
	t->v += lz;
	t->lz += lz;
}
void push_down(node *t) {
	if(!t)
		return;
	apply(t->lz, t->l), apply(t->lz, t->r);
	t->lz = 0;
}
void push_up(node *t) {
	if(!t)
		return;
	t->sm = sm(t->l) + sm(t->r) + t->v * t->cnt;
	t->sz = sz(t->l) + sz(t->r) + t->cnt;
}
node* rotl(node *x) {
	node *y = x->r, *a = y->l;
	push_down(x), push_down(y);
	y->l = x, x->r = a;
	push_up(x), push_up(y);
	return y;
}
node* rotr(node *y) {
	node *x = y->l, *a = x->r;
	push_down(x), push_down(a);
	x->r = y, y->l = a;
	push_up(y), push_up(x);
	return x;
}
node* ins(ll v, node* t, int cnt = 1) {
	if(cnt <= 0)
		return t;
	if(!t)
		return new node(v, cnt);
	push_down(t);
	if(v < t->v) {
		t->l = ins(v, t->l, cnt);
		if(t->l->p > t->p)
			t = rotr(t);
	} else if(v > t->v) {
		t->r = ins(v, t->r, cnt);
		if(t->r->p > t->p)
			t = rotl(t);
	} else
		t->cnt++;
	push_up(t);
	return t;
}
//delete every node keeping everything idx<k
node* del(int k, node* t) {
	if(!t || k <= 0)
		return nullptr;
	push_down(t);
	if(k <= sz(t->l))
		return del(k, t->l);
	k -= sz(t->l);
	t->cnt -= max(0, t->cnt - k);
	k -= t->cnt;
	t->r = del(k, t->r);
	push_up(t);
	return t;
}
//sum of v of every node with idx<k
ll query(int k, node* t) {
	if(!t || k <= 0)
		return 0;
	push_down(t);
	if(t->sz <= k)
		return t->sm;
	ll res = 0;
	res += query(k, t->l);
	k -= sz(t->l);
	res += t->v * min(t->cnt, max(k, 0));
	k -= t->cnt;
	res += query(k, t->r);
	return res;
}

void pt(node *t, int ind = 0) {
	for(int i = 0; i < ind; i++)
		printf(" ");
	if(!t) {
		printf("empty\n");
		return;
	}
	printf("v=%lld*%d sm=%lld lz=%lld sz=%d\n", t->v, t->cnt, t->sm, t->lz, t->sz);
	pt(t->l, ind + 2);
	pt(t->r, ind + 2);
}

int main() {
	srand(time(0));
	int n;
	ll k;
	scanf("%d %lld", &n, &k);
	node* t = nullptr;
	for(int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		ll ccost = k - query(v, t) - v;
		if(ccost < 0)
			printf("-1\n"),
				   t = ins(-1, t);
		else {
			printf("%lld\n", ccost);
			int rm = sz(t);
			t = del(v, t);
			rm = rm - sz(t);
			apply(1, t);
			t = ins(ccost, ins(0, t, rm) );
		}
	}
}
