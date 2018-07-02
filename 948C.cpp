#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int v[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	ll ttmp = 0;
	multiset<ll> piles;
	for(int i = 0; i < n; i++) {
		piles.insert(v[i]+ttmp);
//        cout << "ins"<<v[i]<<endl;
		int t;
		scanf("%d", &t);
		ll res = 0;
//		cout << " ctmp "<<ttmp+t<<endl;
		while(!piles.empty()) {
			auto x = piles.begin();
			ll dx = *x;
			if(dx > ttmp+t)
				break;
//            cout << "  e "<<dx<<endl;
			res +=  dx- ttmp;
			piles.erase(x);
		}
		res += piles.size() * t;
		printf("%I64d ", res);
		ttmp += t;
	}
}
