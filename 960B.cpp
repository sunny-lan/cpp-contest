#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 1401

ll a[MAXN];

int main() {
	int n, k1, k2;
	scanf("%d %d %d", &n, &k1, &k2);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	priority_queue<ll> dif;
	for(int i = 0; i < n; i++) {
		ll b;
		scanf("%I64d", &b);
        dif.push(abs(a[i] - b));
	}
	for(int i = 0; i < k1 + k2; i++) {
		ll v = dif.top();
		dif.pop();
		dif.push(abs(v - 1));
	}
	ll tot = 0;
	while(!dif.empty()) {
		ll ree = dif.top();
		dif.pop();
		tot += ree*ree;
	}
	printf("%I64d\n", tot);
}
