#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	int q;
	scanf("%I64d %d", &n, &q);
	for(int i = 0; i < q; i++) {
		ll x;
		scanf("%I64d", &x);
		ll cur = x;
		while(cur % 2 == 0 )
			cur += n - cur / 2;
		printf("%I64d\n", (cur + 1) / 2);
	}
}
