#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 110
#define MAXBS 1500000

int n, m;
int x[MAXN], y[MAXN];
int sm[MAXN], pm[MAXN];
int sv[MAXN], pv[MAXN];

ll f(int s) {
	ll tot = 0;
	for(int i = 0; i < n; i++) {
		ll need = x[i] * s - y[i];
		if(need <= 0)
			continue;
		ll mini = 1ll<<60;
		for(int j = 0; j <= 10000; j++)
		{
			ll need2 = max(need - sm[i] * j, 0ll);
			ll lg = (need2 + sv[i] - 1) / sv[i];
			mini = min(mini, pm[i] * j + pv[i] * lg);
		}
		tot += mini;
	}
	return tot;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d %d %d %d", &x[i], &y[i], &sm[i], &pm[i], &sv[i], &pv[i]);

	int hi = MAXBS, lo = 0;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
//		cout <<"f("<<mid<<")="<<f(mid)<<endl;
		if(f(mid) <= m)
			lo = mid+1;
		else
			hi = mid;
	}
	printf("%d\n", lo-1 );
}
