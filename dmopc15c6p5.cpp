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
#include <set>

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 3000000

int arr[MAXN];
multiset<int>::iterator it[MAXN];

int main() {
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++)
		scan(arr[i]);

	multiset<int> custs;
	int b = 0;
	ll tot = 0;
	for (int a = 0; a < n; a++) {
		while (b<n) {
			int diff;
			if (custs.empty()) diff = 0;
			else diff = abs(max(*custs.rbegin(), arr[b]) - min(*custs.begin(), arr[b]));
			if (diff > k)break;
			it[b]=custs.insert(arr[b]);
			b++;
		}

		tot += b - a;

		if (custs.empty())continue;
		custs.erase(it[a]);
	}

	printf("%lld\n", tot);
}