#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000000ll

typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	for(int tes = 0; tes < t; tes++) {
		int x;
		scanf("%d", &x);
		for(ll n = 1; n * n <= MAXN; n++) {
			ll hi = n+1, lo = 1;
			while(lo < hi) {
				ll m = (hi + lo) / 2;
				ll thing = ceil(n / (2.0 * m - 1));
				ll kust = n * n - thing * thing;
                    if(kust < x) {
					lo = m+1;
				}
				else if(kust > x) {
					hi=m;
				} else {
					printf("%I64d %I64d\n", n, m);
					goto outer;
				}
			}
		}
		printf("-1\n");
	outer:
		continue;
	}
}
