#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long fuck(long long n)
{
    long long maxPrime = -1;

    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
    }

    if (n > 2)
        maxPrime = n;

    return maxPrime;
}


int main() {
	int n;
	scanf("%d", &n);
	ll tgc;
	scanf("%lld", &tgc);
	for(int i = 1; i < n; i++)
	{
		ll cur;
		scanf("%lld", &cur);
		tgc = __gcd(tgc, cur);
	}
	ll alt=fuck(tgc);
if(alt!=-1)
	printf("%lld", alt);
	else
	printf("DNE");
}
