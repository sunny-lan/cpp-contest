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
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


#define MAXN 101

ll v[MAXN];


int main() {
	ll n, q; cin >> n >> q;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		v[i] = x;
	}
	for (ll i = 0; i < q; i++) {
		string op; ll a; ll b; cin >> op >> a >> b;
		a--;
		if (op == "S")
		{
			v[a] = b;
		}
		else {
			ll maxi = 0;
			for (ll st = a; st < b; st++) {
				ll subsum = 0;
				for (ll ed = st; ed < b; ed++)
				{
					subsum += v[ed];
					maxi = max(maxi, subsum);
				}
			}
			cout << maxi << endl;
		}
	}
	cin >> q;
}