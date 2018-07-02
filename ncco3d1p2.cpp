#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 10001

int x[MAXN];
int ptr[MAXN], p[MAXN];
bool pred(int a, int b) {
	return x[a] < x[b];
}

bool v[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	ll gmn=1ll<<60;
	for(int i = 0; i < n; i++)
		scanf("%d", &x[i]),ptr[i]=i,
		gmn=min(gmn, (ll)x[i]);
	sort(ptr, ptr + n, pred);
	for(int i = 0; i < n; i++)
		p[ptr[i]] = i;
    ll tot=0;
	for(int i = 0; i < n; i++) {
		if(v[i])
			continue;
		int tmp = i;
		ll mini=1ll<<60;
		ll sm=0, cnt=0;
		do {
			v[tmp] = true;
            sm+=x[tmp];
            mini=min(mini, (ll)x[tmp]);
            cnt++;
			tmp = p[tmp];
		} while(tmp != i);
		if(cnt==1)continue;
		tot+=min((cnt-1)*mini+(sm-mini), gmn*cnt+sm+gmn+mini);
	}
	printf("%lld\n", tot);
}
