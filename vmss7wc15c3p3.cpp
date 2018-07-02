#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef long long ll;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100010

int n, k;

ll p[MAXN];
int fx[MAXN];


bool check(ll f) {
	ll fl = f;
	int cnt = 0;
	ll prev = 0;
	for (int i = 0; i < n; i++) {
		ll curr = p[i];
		ll dist = curr - prev;
		if (dist > f)return false;
		//if distance to come to curr too big
		if (dist > fl)
			//refill at prev
			fl = f, cnt++;
		//come to curr
		fl -= dist;
		prev = curr;
		//if forced to refill
		if (fx[i])
			fl = f, cnt++;
	}
	if (k == 100000) {
		if (cnt >= k)return false;
	}
	else
		if (cnt > k)return false;
	return true;
}

#define BSLIM 1000000001

int main() {
	scan(n); scan(k);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scan(p[i]); scan(fx[i]);
		if (fx[i])cnt++;
	}
	if (cnt > k) { printf("DEA Bust!\n"); return 0; }

	ll lo = 0,
		hi = BSLIM;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("%lld\n", lo);
	cin >> lo;
}