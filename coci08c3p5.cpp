#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
	int v, p, lc, rc;
	node* l = nullptr, *r = nullptr;
	node(int _v, int _c) {
		v = _v;
		p = rand();
		lc=rc = _c;
	}
};

node* rotr(node *x) {
	node *y = x->l,
		  *a = y->r;
	y->r = x;
	x->l = a;
	x->lc=y->rc;
	return y;
}

node* rotl(node *y) {
	node *x = y->r,
		  *a = x->l;
	x->l = y;
	y->r = a;
	y->rc = x->lc;
	return x;
}

ll tot = 0;

node* insert(int v, node* t, int pc = 0) {
	if(t) {
		if(v < t->v)
		{
			t->l = insert(v, t->l, t->lc + 1);
			if(t->l->p > t->p)
				t = rotr(t);
		} else {
			t->r = insert(v, t->r, t->rc + 1);
			if(t->r->p > t->p)
				t = rotl(t);
		}
		return t;
	} else {
		tot += pc;
		return new node(v, pc);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	node* rt = nullptr;
	for(int i = 0; i < n; i++)    {
		int v;
		scanf("%d", &v);
		rt = insert(v, rt);
//        printtree(rt);
		printf("%lld\n", tot);
	}
}
