#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
#define f first
#define s second

#define MAXN 100002
#define MAXB 17

struct seg {
	int l, r;
	int _mx;
	int blk;
	int mx(){
        return blk==0?_mx:0;
	}
} t[MAXN * 3];

void push_up(int i) {
        t[i]._mx=max(t[i*2].mx(), t[i*2+1].mx());
}

int ch[MAXN];
void build(int l, int r, int i = 1) {
	t[i].l = l, t[i].r = r;
	 t[i].blk = 0;
	if(l + 1 == r) {
		t[i]._mx = ch[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, i * 2), build(mid, r, i * 2 + 1);
	push_up(i);
}

void update(int l, int r, int x, int i = 1) {
	if(t[i].l >= r || t[i].r <= l)
		return;
	if(t[i].l >= l && t[i].r <= r) {
		t[i].blk+=x;
		return;
	}
	update(l, r, x, i * 2), update(l, r, x, i * 2 + 1);
	push_up(i);
}

int query(int l, int r, int i = 1) {
	if(t[i].l >= r || t[i].r <= l)
		return 0;
	if(t[i].l >= l && t[i].r <= r)
		return t[i].mx();
	return max(query(l, r, i * 2), query(l, r, i * 2 + 1));
}

ll d[MAXN];
vector<pil> chil[MAXN];
ll dst[MAXN];
int sp[MAXB][MAXN];
int pre[MAXN], post[MAXN];
int h[MAXN];
int td = 0;
void dfs(int i = 0) {
	ch[td] = h[i], pre[i] = td++;
	for(int bs = 2, lvl = 1; bs <= h[i]; lvl++, bs <<= 1)
		sp[lvl][i] = sp[lvl - 1][sp[lvl - 1][i]];
	for(pil k : chil[i])
		h[k.f] = h[i] + 1, dst[k.f] = dst[i] + k.s, dfs(k.f);
	post[i] = td ;
}

int grp[MAXN];
int lst[MAXN];
int n;

void upd(int i, ll nd) {
	if(lst[i] != -1)
		if(--grp[lst[i]] == 0)
			update(pre[lst[i]], post[lst[i]], -1);
	int cur = i, lvl = MAXB - 1;
	while(cur > 0 && lvl >= 0)
		if(dst[sp[lvl][cur]] >= nd)
			cur = sp[lvl][cur];
		else
			lvl--;
	if(dst[cur] >= nd) {
		if(++grp[cur] == 1)
			update(pre[cur], post[cur], 1);
		lst[i] = cur;
	} else
		lst[i] = -1;
}
int main() {
	memset(lst, -1, sizeof lst);
	scanf("%d", &n);
	n++;
	for(int i = 1; i < n; i++)
		scanf("%lld", &d[i]);
	for(int i = 1; i < n; i++) {
		ll t;
		scanf("%d %lld", &sp[0][i], &t);
		chil[sp[0][i]].push_back({i, t});
	}
	dfs();
	build(0, n);
	for(int i = 1; i < n; i++)
		upd(i, d[i]);
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; i++) {
		int a;
		ll d;
		scanf("%d %lld", &a, &d);
		upd(a, d);
		printf("%d\n", query(pre[0], post[0]));
	}
}
