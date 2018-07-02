#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
#define f first
#define s second

ll fac(int i){
    ll res=1;
    for(int j=2;j<=i;j++)
        res=res*j%mod;
    return res;
}



int main() {
	freopen("C:\\Users\\Sunny\\Desktop\\DATA11.txt", "r", stdin);

	for(int test = 0; test < 10; test++) {
		int b, g;
		cin >> b >> g;
		ll cnt = 0;
		int tot = b + g;
		for(int i = 0; i < (1 << tot); i++) {
			int boy = 0;
			for(int j = 0; j < tot; j++)
				if((i >> j) & 1)
					boy++;
			if(boy != b)
				goto outer;
			for(int j = 0; j < tot; j++) {
				if((i >> j) & 1) {
					for(int bk = j, fk = j; bk >= 0 && fk < tot; bk--, fk++) {
						if(((i >> bk) & 1) == 0)
							if(((i >> fk) & 1) == 0)
							{
								cnt++;
								goto outer;
							}
					}
				}
			}
		outer:
			continue;
		}
		printf("%lld\n", cnt%mod*fac(b)%mod*fac(g)%mod);
	}
	return 0;
}

