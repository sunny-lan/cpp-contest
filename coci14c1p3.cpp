#ifdef DMOJ

#include <bits/stdc++.h>

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

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXK 50010
#define MAXL 1000010

vector<pii> queries[26];
ll psa[MAXL];
ll ans[MAXK];

int main() {
	ll n; scan(n);
	string w; cin >> w;
	ll l = w.length();
	ll k; scan(k);
	for (ll i = 0; i < k; i++) {
		ll a; char c; scanf("%d %c", &a, &c);
		queries[c - 'A'].push_back({ a ,i });
	}

	for (ll i = 0; i < 26; i++) {
		memset(psa, 0, sizeof psa);
		char c = 'A' + (char)i;
		for (ll j = 0; j < l; j++) {
			if (w[j] == c)psa[j + 1]++;
			psa[j + 1] += psa[j];
		}
		for (pii q : queries[i]) {
			ll a = q.first, line = a,
				b = a - 1;
			if (a & 1) b >>= 1;
			else a >>= 1;
			a %= l, b %= l;
			ll startIdx = a*b%l;
			ll endIdx = (startIdx + line) % l;
			ll actlen =  line - (l - startIdx) - endIdx;
			ll cnt = actlen / l;
			if (actlen<0)ans[q.second] = psa[endIdx] - psa[startIdx];
			else ans[q.second] = psa[l] * cnt + psa[endIdx] + (psa[l] - psa[startIdx]);
		}
	}

	for (ll i = 0; i < k; i++)
		printf("%lld\n", ans[i]);

	cin >> l;
}