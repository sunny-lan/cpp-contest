#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

#define MAXN 100001

ll p[MAXN];
int fr[MAXN];
int n, k;

int func(ll f) {
	ll tank = f, prev = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		ll dist = p[i] - prev;
		//cannot reach no matter waht
		if (dist > f)return MAXN+1;
		
		//cannot reach without refuel
		if (dist > tank)
		{
			cnt++;
			tank = f;
		}

		tank -= dist;
		prev = p[i];

		//forced
		if (fr[i] == 1)
		{
			cnt++;
			tank = f;
		}
	}
	if (k != n)cnt++;
	return cnt;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld %d", &p[i], &fr[i]);
	ll hi = 1000000001, lo = 0;
	while (lo < hi) {
		ll mid = (hi + lo) / 2;
		if (func(mid) <= k)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (lo >= 1000000000)
		printf("DEA Bust!\n");
	else
		printf("%lld\n", lo);
	cin >> lo;
}