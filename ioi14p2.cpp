#include <bits/stdc++.h>
using namespace std;

struct seg {
	int l, r;
	int lwr, upr;
	bool llz, ulz ;
};

#define MAXN 2000000

seg t[MAXN * 3];

void applyu( int upr, int i) {
	t[i].lwr = min(t[i].lwr, upr);
	t[i].upr = min(t[i].upr, upr);
	t[i].ulz = true;
}

void applyl( int lwr, int i) {
	t[i].lwr = max(t[i].lwr, lwr);
	t[i].upr = max(t[i].upr, lwr);
	t[i].llz = true;
}

void push_down(int i) {
	if(t[i].ulz)
		applyu( t[i].upr, i * 2), applyu( t[i].upr, i * 2 + 1);
	if(t[i].llz)
		applyl( t[i].lwr, i * 2), applyl( t[i].lwr, i * 2 + 1);
	t[i].ulz = t[i].llz = false;
	t[i].upr=INT_MAX,t[i].lwr=-INT_MAX;
}

void build(int l, int r, int i = 1) {
	t[i].l = l, t[i].r = r;
	t[i].lwr = -INT_MAX, t[i].upr = INT_MAX;
	t[i].llz = false, t[i].ulz = false;
	if(l + 1 == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, i * 2), build(mid, r, i * 2 + 1);
}

void update(int l, int r, int h, bool lm, int i = 1) {
	if(t[i].l >= r || t[i].r <= l)
		return;
	if(t[i].l >= l && t[i].r <= r)
	{
		if(lm)
			applyl(h, i);
		else
			applyu(h, i);
	}
	else{
	push_down(i);
		update(l, r, h, lm, i * 2), update(l, r, h, lm, i * 2 + 1);
	}
}

int *ans;
void collect( int i = 1) {
	if(t[i].l + 1 == t[i].r)
		ans[t[i].l] = max(min(0, t[i].upr), t[i].lwr);
	else
		push_down(i), collect(i * 2), collect(i * 2 + 1);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
	build(0, n);
	for(int i=0;i<n;i++)
        finalHeight[i]=0;
	ans = finalHeight;
	for(int i = 0; i < k; i++) {
		update(left[i], right[i] + 1, height[i], op[i]==1);
	}
	collect();
}
