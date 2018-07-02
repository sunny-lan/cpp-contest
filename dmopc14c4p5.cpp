#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
void update(int p, T v, T bit[], int sz) {
	for(p++; p < sz; p += p & -p)
		bit[p] += v;
}

template <typename T>
T query(int p, T bit[]) {
	T res = 0;
	for(p++; p > 0; p -= p & -p)
		res += bit[p];
	return res;
}

const int BS = 350010, OFS = 120005;

ll tot = 0;
int tcnt = 0;
int bita[BS];
ll bitd[BS];
int qa(int p) {
	return query(p + OFS, bita);
}
ll qd(int p) {
	return query(p + OFS, bitd);
}
void ua(int p) {
	tot += p;
	tcnt++;
	update(p + OFS, 1, bita, BS);
	update(p + OFS, (ll)p, bitd, BS);
}

int bitb[BS];
ll bitc[BS], bite[BS];
int cnt = 0;
ll tem = 0, shf = 0;
int qb(int p) {
	return query(p + shf, bitb);
}
ll qc(int p) {
	return query(p + shf, bitc) - 2 * (tem * qb(p) - query(p + shf, bite));
}
void ub(int p) {
	tot += p;
	cnt++;
	tcnt++;
	update(p + shf, (ll)p, bitc, BS);
	update(p + shf, 1, bitb, BS);
	update(p + shf, tem, bite, BS);
}
void sba(ll v) {
	tot -= v * cnt;
	tem++;
	shf += v;
}
ll dsm(int i) {
	ll lcnt = (qb(i) + qa(i)), rcnt = tcnt - (qb(i - 1) + qa(i - 1));
	return ((tot - (qd(i - 1) + qc(i - 1))) - rcnt * i) + (lcnt * i - (qd(i) + qc(i)));
}
int div_floor(int x, int y) {
	int q = x / y;
	int r = x % y;
	if ((r != 0) && ((r < 0) != (y < 0)))
		--q;
	return q;
}
int median() {
	int med = tcnt / 2 + 1;
	int lo = -OFS, hi = 200001;
	while(lo < hi) {
		int mid = div_floor(lo + hi, 2);
		int res = qa(mid) + qb(mid);
		if(res >= med)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}
void init() {
	tot = tcnt = 0;
	memset(bita, 0, sizeof bita);
	memset(bitb, 0, sizeof bitb);
	memset(bitc, 0, sizeof bitc);
	memset(bitd, 0, sizeof bitd);
	memset(bite, 0, sizeof bite);
	shf = cnt =  tem = 0;
}

#define MAXN 200000

int n, k;
ll h[MAXN];
ll td[MAXN];

ll wa() {
	if(k == 1)
		return 0;
	init();
	ua(h[0]);
	ll mini = LLONG_MAX;
	int ins = 1;
	int rm = 1;
	while(ins + 2 <= n) {
		sba(2);
		td[ins] = tem;
		ub(h[ins++] - 1);
		td[ins] = tem;
		ub(h[ins++]);
		update(h[rm] - rm + shf, -1, bitb, BS);
		update(h[rm] - rm + shf, -(h[rm] - (rm % 2 ? 1 : 0)), bitc, BS);
		update(h[rm] - rm + shf, -td[rm], bite, BS);
		tot -= h[rm] - rm;
		cnt--;
		tcnt--;
		ua(h[rm] - rm);
		if(tcnt >= k)
			mini = min(mini, dsm(median()));
		rm++;
	}
	if(mini == LLONG_MAX)
		mini = -1;
	return mini;
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%lld", &h[i]);
	printf("%lld\n", wa());
}
