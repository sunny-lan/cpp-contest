#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
#define f first
#define s second

#define MAXL 62

ll shf[MAXL];

pil lvl(ll inp) {
	ll sz = 1;
	int lvl = 0;
	while(inp) {
		inp /= 2;
		lvl++;
		sz <<= 1;
	}
	return {lvl - 1, sz >> 1};
}

int main() {
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int op;
		scanf("%d", &op);
		if(op == 3) {
			ll x;
			scanf("%I64d", &x);
			pil lv = lvl(x);
			cout << "re" << lv.f << " " << lv.s << endl;
			while(lv.f >= 0) {
                ll ckust=(1<<lv.f)-1;
                x-=ckust;
				x = (x - shf[lv.f] + lv.s)%lv.s ;
				x+=ckust;
				printf("%I64d ", x);
				lv.f--, lv.s >>= 1, x >>=1;
			}
			printf("\n");
		} else {
			ll x, k;
			scanf("%I64d %I64d", &x, &k);
			pil lv = lvl(x);
			cout << "re" << lv.f << " " << lv.s << endl;
			if(op == 1) {
				shf[lv.f] += k;
				shf[lv.f] %= lv.s;
			} else {
				for(int j = lv.f; j < MAXL; j++)
				{
					k %= lv.s;
					shf[j] += k;
					shf[j] %= lv.s;
					lv.s <<= 1, k <<= 1;
				}
			}
		}
	}
}

