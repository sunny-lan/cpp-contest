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
#include <stack>
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

int main() {
	int n; scan(n);
	stack<pair<ll, ll>> s;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		ll curr; scan(curr);
		ll c = 1;
		while (!s.empty()) {
			ll h = s.top().first;
			ll b = s.top().second;

			if (h == curr) {
				c += b;
				cnt += b;
				break;
			}
			cnt++;
			if (h > curr) { c++;  break; }

			s.pop();
		}
		s.push({ curr ,c });
	}
	cout << cnt << endl;
	cin >> n;
}