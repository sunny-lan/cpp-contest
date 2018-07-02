#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 200005;

vector<pii> adj[N];

ll dp[N][50];

ll f(int u, int v, int p) {
	if(adj[u].size() == 1 && u != 0)
		return p;
	ll &res = dp[u][p];
	if(res == -1) {
		res = p;
		for(pii i : adj[u]){
			if(i.f != v) {
                ll alt=1ll<<40;
				for(int j = 1; j < 50; ++j)
					if((i.s && __gcd(j, p) > 1) || (!i.s && __gcd(j, p) == 1))
						alt = min(alt, f(i.f, u, j));
                res+=alt;
			}
		}
	}
	return res;
}


int main() {
	memset(dp, -1, sizeof dp);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[--a].pb({--b, c});
		adj[b].pb({a, c});
	}

	ll ans=1ll<<60;
	for(int i=1;i<50;++i)
        ans=min(ans,f(0,-1,i));

    printf("%lld\n",ans);
	return 0;
}
