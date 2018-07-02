#ifdef DMOJ

#include <bits/stdc++.h>

#define gc getchar_unlocked

void scan(long long &x)
{
	register long long c = gc();
	x = 0;
	int neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

void scan(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <cstdio>

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 100001

#define MAXV 1000001

ll f[MAXN];

ll cnt[MAXV];

int main() {
	ll n, k; scan(n); scan(k);
	for (ll i = 0; i < n; i++)
		scan(f[i]);

	ll distinct = 0;
	ll b = 0;
	ll tot = 0;
	for (ll a = 0; a < n; a++) {
		while (b <= n && distinct < k) {
			if (cnt[f[b]] == 0)
				distinct++;
			cnt[f[b]]++;
			b++;
		}

		if (distinct < k)
			break;

		tot += n - b + 1;
		cnt[f[a]]--;
		if (cnt[f[a]] == 0)
			distinct--;
	}

	cout << tot << endl;
	cin >> tot;
}