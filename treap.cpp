#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

struct node
{
	int v, sz = 1, p, cnt = 1;
	node *l = nullptr, *r = nullptr;

	node(int _v)
	{
		v = _v;
		p = rand();
	}
};

int sz(node* x) {
	return x ? x->sz : 0;
}

node *rt = nullptr;

void push_up(node* x)
{
	x->sz = x->cnt;
	if (x->l)
		x->sz += sz(x->l);
	if (x->r)
		x->sz += sz(x->r);
}

node* rotl(node *x)
{
	node *y = x->r,
		*t2 = y->l;
	x->r = t2;
	y->l = x;
	push_up(x);
	push_up(y);
	return y;
}

node* rotr(node *y)
{
	node *x = y->l,
		*t2 = x->r;
	x->r = y;
	y->l = t2;
	push_up(y);
	push_up(x);
	return x;
}

node* ins(int v, node* t)
{
	if (t)
	{
		if (v < t->v)
		{
			t->l = ins(v, t->l);
			if (t->l->p > t->p)
				t = rotr(t);
		}
		else if (v == t->v)
			t->cnt++;
		else
		{
			t->r = ins(v, t->r);
			if (t->r->p > t->p)
				t = rotl(t);
		}
		push_up(t);
		return t;
	}
	else
	{
		return new node(v);
	}
}

node* del(node* x)
{
	if (x->l && x->r)
	{
		x = rotl(x);
		x->l = del(x->l);
		push_up(x);
		return x;
	}
	node* replace = nullptr;
	if (x->l) replace = x->l;
	if (x->r) replace = x->r;
	delete x;
	return replace;
}

node* del(int v, node* t)
{
	if (!t) return t;
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

node* gidx(int i, node* t)
{
	int lsz = sz(t->l);
	if (i <= lsz)
		return gidx(i, t->l);
	if (i <= lsz + t->cnt)
		return t;
	return gidx(i - (lsz + t->cnt), t->r);
}

int fidx(int v, node* t)
{
	if (!t)return -1;
	if (v < t->v)
		return fidx(v, t->l);
	if (v == t->v)
		return sz(t->l);
	int alt = fidx(v, t->r);
	if (alt == -1)return alt;
	return alt + sz(t->l) + t->cnt;
}

void print(node* t) {
	if (!t)return;
	print(t->l);
	for (int i = 0; i < t->cnt; i++)
		printf("%d ", t->v);
	print(t->r);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);
		rt = ins(v, rt);
	}
	int last = 0;
	for (int i = 0; i < m; i++)
	{
		char c;
		int x;
		scanf(" %c %d", &c, &x);
		x ^= last;
		if (c == 'I')
			rt = ins(x, rt);
		else if (c == 'R')
			rt = del(x, rt);
		else if (c == 'S')
			printf("%d\n", last = gidx(x, rt)->v);
		else {
			int alt = fidx(x, rt);
			printf("%d\n", last = (alt == -1 ? alt : alt + 1));
		}
	}
	print(rt);
	cin >> n;
}
