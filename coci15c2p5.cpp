#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cstdio>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

#define MAXN 1000010

int bit[MAXN];

ll val[MAXN];
ll psa[MAXN];

int tmp[MAXN];
int mapping[MAXN];

inline bool pred(int a, int b) {
	return psa[a] < psa[b];
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++)
		scan(val[i]);

	ll p; scan(p);
	for (int i = 0; i < n; i++) {
		psa[i + 1] = psa[i] + (val[i] - p);
		tmp[i] = i;
	}
	tmp[n] = n;

	n++;
	sort(tmp, tmp + n, pred);
	
	int g = 0;
	ll last = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		if (psa[tmp[i]] != last) {
			last = psa[tmp[i]];
			g++;
		}
		mapping[tmp[i]] = g;
	}

	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		int u = mapping[i];
		for (int x = u; x > 0; x -= x&-x)
			cnt += bit[x];
		for (int x = u; x <= g; x += x&-x)
			bit[x]++;
	}

	printf("%lld\n", cnt);
}