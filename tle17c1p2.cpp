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
using namespace std;

#define memeset memset

template<typename T>
inline T INF(T a) { return a == -1 ? INT_MAX : a; }
inline int _INF(int a) { return a == INT_MAX ? -1 : a; }

template<typename T>
inline T INF_MAX(T a, T b) { return INF(a) > INF(b) ? a : b; }

template<typename T>
inline T INF_MIN(T a, T b) { return INF(a) < INF(b) ? a : b; }


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

unordered_map<string, ll> e;

#define MAXN 1001

pair<ll, ll> loc[MAXN];

int main() {
	ll f; cin >> f;
	for (ll i = 0; i < f; i++) {
		string s; cin >> s;
		ll e1; cin >> e1;
		 e[s]=e1;
	}
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) {
		string t; ll d; cin >> t >> d;
		loc[i] = { d,e[t] };
	}
	sort(loc, loc + n);
	ll pos = 0;
	ll e = 0;
	ll i;
	for (i = 0; i < n; ) {
		if (pos == loc[i].first) {
			e += loc[i].second;
			i++;
		}
		else {
			if (e >= (loc[i].first - pos) ) {
				e -= (loc[i].first - pos);
				pos = loc[i].first;
			}
			else {
				break;
			}
		}
	}
	cout << i << endl;
	cin >> f;
}