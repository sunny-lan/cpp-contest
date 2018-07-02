#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <unordered_set>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

typedef long long ll;
typedef pair<ll, pair<ll, ll>> triple;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}


size_t hashT(const triple& t) {
	return (size_t)t.first ^ (size_t)t.second.first ^ (size_t)t.second.second;
}

unordered_set<triple, size_t(*)(const triple& t)> ratios(0, hashT);

int main() {
	ll x1, y1, z1; scan(x1); scan(y1); scan(z1);
	int n; scan(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		ll x, y, z; scan(x); scan(y); scan(z);
		x -= x1, y -= y1, z -= z1;
		ll c = gcd(abs(x), gcd(abs(y), abs(z)));
		triple t = { x / c,{y / c,z / c} };
		if (ratios.find(t) == ratios.end())
		{
			cnt++;
			ratios.insert(t);
		}
	}
	printf("%d\n", cnt);
	cin >> x1;
}