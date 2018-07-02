#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	ll n;
	scanf("%I64d", &n);
	unordered_map<ll, ll> cnt;
	ull neg = 0ull, pos = 0ull;
	for(ll i = 0; i < n; i++) {
		ll a;
		scanf("%I64d", &a);
		ll cancer = (i - (n - i - 1)) * a;
		if(cancer <= 0)
			neg += (ull)(-cancer);
		else
			pos += (ull)(cancer);
		neg += (ull)(cnt[a - 1]);
		pos += (ull)(cnt[a + 1]);
		cnt[a]++;
	}
	if(neg > pos)
		printf("-%I64u", neg - pos);
	else
		printf("%I64u", pos - neg);
}
