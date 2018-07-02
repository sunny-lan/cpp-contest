#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pli;
#define f first
#define s second

#define MAXN 100000

pli a[MAXN];
int k;
bool pred(pli x, pli y) {
	return x.f + x.s * k < y.f + y.s * k;
}
int n, s;
ll f() {
	sort(a, a + n, pred);
	ll tot = 0;
	for(int i = 0; i < k; i++){
		tot += a[i].f + a[i].s * k;
	}
	return tot;
}

int main() {
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i].f), a[i].s = i + 1;
	int lo = 0, hi = n + 1;
	ll cst;
	while(lo < hi) {
		k = (lo + hi) / 2;
		cst = f();
		if(cst > s)
			hi=k;
		else
			lo=k+1;
	}
	k = lo-1;
	printf("%d %lld\n", k, f());
}
