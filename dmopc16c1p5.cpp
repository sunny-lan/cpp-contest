#ifdef DMOJ
#include <bits/stdc++.h>
#else
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#endif // DMOJ
using namespace std;
typedef long long ll;
//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 500010
int n;
int bit[MAXN];
void update(int p, int v) {
	for (int x = p; x <= n; x += x&-x)bit[x] += v;
}
int query(int p) {
	int res = 0;
	for (int x = p; x > 0; x -= x&-x)res += bit[x];
	return res;
}
int main() {
	scan(n);
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		int x; scan(x);
		int top = query(x);
		int bot = i - top;
		cnt += min(top, bot);
		update(x, 1);
	}
	printf("%lld\n", cnt);
}