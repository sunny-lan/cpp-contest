#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second
#define MAXN 500000

int N;
ll M,sLoc[MAXN], tLoc[MAXN];

ll dis(ll a,ll b){
    ll x=abs(a-b)%M;
    return min(x, M-x)%M;
}

int main() {
	freopen("C:\\Users\\Sunny\\Desktop\\DATA41.txt", "r", stdin);
	for(int tst = 0; tst < 10; tst++) {
		scanf("%d%lld", &N, &M);
		for(int i = 0; i < N; i++)
			scanf("%lld", &sLoc[i]);
		for(int i = 0 ; i < N; i++)
			scanf("%lld", &tLoc[i]);
		sort(sLoc, sLoc + N);
		sort(tLoc, tLoc + N);
        for()
        printf("%lld\n",ans);
	}
	return 0;
}

