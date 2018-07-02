#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int itoa(ll num, int* str, int base)
{
	int i = 0;
	if (num == 0) {
		str[i++] = 0;
		return i;
	}
	while (num != 0) {
		ll rem = num % base;
		str[i++] = rem ;
		num = num / base;
	}
	return i;
}

int main() {
	ll x;
	scanf("%lld", &x);
	set<ll> kms;
	for(ll bs = 2; bs * bs <= x; bs++) {
		int buf[40];
		int len = itoa(x, buf, bs);
		for(int i = 0; i < len; i++)
			if(buf[i] != buf[len - i - 1])
				goto outer;
		kms.insert(bs);
	outer:
		continue;
	}
	for(ll a = 1; a * a <= x; a++)
		if(x % a == 0) {
			ll b = (x / a) - 1;
			if(x <= (b - 1)*b + (b - 1))
				kms.insert(b);
		}
	for(ll i : kms)
		printf("%lld\n", i);
}
