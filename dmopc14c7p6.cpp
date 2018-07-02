#include <bits/stdc++.h>
using namespace std;

struct seg {
	int l, r;
	int mini = 0;
	int lazy = 0;
	bool flg = false;
};

#define MAXN 100000

seg tree[MAXN * 3];

void push_up(int i) {
	tree[i].mini = min(tree[i * 2].mini, tree[i * 2 + 1].mini);
}

void apply(int i, int lz) {
	tree[i].mini += lz;
	tree[i].lazy += lz;
	tree[i].flg = true;
}

void push_down(int i) {
	if(!tree[i].flg)
		return;
	apply(i * 2, tree[i].lazy), apply(i * 2 + 1, tree[i].lazy);
	tree[i].flg = false;
	tree[i].lazy = 0;
}

void build(int l, int r, int i = 1) {
	tree[i].l = l, tree[i].r = r;
	if(l + 1 == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, i * 2), build(mid, r, i * 2 + 1);
}

void update(int l, int r, int x, int i = 1) {
	if(tree[i].l >= r || tree[i].r <= l)
		return;
	if(tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	push_down(i);
	update(l, r, x, i * 2), update(l, r, x, i * 2 + 1);
	push_up(i);
}

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	build(0, n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]), a[i]--;
	int x = 0, y = 1;
	int maxi=0;
	while(y < n) {
		update(0, a[x], 2);
		update(0, a[y], -1);
		update(0, a[y - 1], -1);
        if(tree[1].mini>=0)
            maxi=max(maxi, x+1);
		x++, y += 2;
	}
	printf("%d\n", maxi);
}
