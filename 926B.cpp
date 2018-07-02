#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100001

ll x[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &x[i]);
	sort(x, x + n);
	ll gcd = -1;
	for(int i = 1; i < n; i++) {
		ll dist = x[i] - x[i - 1];
		if(gcd == -1) {
			gcd = dist;
		} else {
			gcd = __gcd(gcd, dist);
		}
	}
	printf("%I64d", ((x[n - 1] - x[0]) / gcd+1)-n);
}
