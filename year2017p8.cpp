#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100000

struct seg {
	int l, r, cnt = 0;
	ll sum = 0, lz = 1;
} t[MAXN * 3];

void push_up(int i) {
	t[i].sum = t[i * 2].sum + t[i * 2 + 1].sum;
	t[i].cnt = t[i * 2].cnt + t[i * 2 + 1].cnt;
}

void apply(int i, ll v) {
	t[i].sum *= v;
	t[i].lz *= v;
}

void push_down(int i) {
	apply(i * 2, t[i].lz), apply(i * 2 + 1, t[i].lz);
	t[i].lz = 1;
}

int nmp[MAXN];

void build(int l, int r, int i = 1) {
	t[i].l = l, t[i].r = r;
	if(l + 1 == r){
        nmp[l]=i;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, i * 2), build(mid, r, i * 2 + 1);
}

void updatem(int r, ll x, int i = 1) {
	if( t[i].l >= r)
		return;
	if(t[i].r <= r )
		return apply(i, x);
	push_down(i);
	updatem( r, x, i * 2), updatem(r, i * 2 + 1);
	push_up(i);
}

void update(int p, ll x, int i = 1) {
	if(p < t[i].l || p >= t[i].r)
		return;
	if(t[i].l + 1 == t[i].r) {
		t[i].sum += t[i].lz * x;
		t[i].cnt++;
		return;
	}
	push_down(i);
	update( p, x, i * 2), update( p, x, i * 2 + 1);
	push_up(i);
}

ll query(int r, int i = 1) {
	if(t[i].l >= r)
		return 0;
	if(t[i].r <= r)
		return t[i].sum;
	push_down(i);
	return query(r, i * 2) + query(r, i * 2 + 1);
}

int queryc(int r, int i = 1) {
	if(t[i].l >= r)
		return 0;
	if(t[i].r <= r)
		return t[i].cnt;
	push_down(i);
	return queryc(r, i * 2) + queryc(r, i * 2 + 1);
}

ll b[MAXN], d[MAXN];
int car[MAXN], ord[MAXN];
bool pred(int x, int y) {
	return b[y] * d[x] + d[y] < b[x] * d[y] + d[x];
}

int n; ll f, tot;
void emp(int i){
    tot*=b[i];
}

void wa(){
	tot = f;
	for(int i = 0; i < n; i++)
		car[i] = i;
	sort(car, car + n);
	for(int i = 0; i < n; i++)
		ord[car[i]] = i;
	build(0, n);
	set<int, bool(*)(int, int)> fs(pred);

	for(int i = 0; i < n; i++) {
		if(b[i] > 1) {

		}
		printf("%lld\n", tot - query(n));
	}
}

int ptr[MAXN];
void ac(){
    for(int i=1;i<=n;i++){
        ptr[i-1]=i-1;
        sort(ptr, ptr+i, pred);
        int cur=f;
        for(int jj=0;jj<i;jj++){
            int j=ptr[jj];
            int alt=b[j]*cur-d[j];
            if(alt>cur)
                cur=alt;
        }
        printf("%d\n", cur);
    }
}

int main() {
	scanf("%d%lld", &n, &f);
	for(int i = 0; i < n; i++)
		scanf("%lld%lld", &b[i], &d[i]);
	printf("ac:\n");
	ac();
	printf("wa:\n");
	wa();
}
