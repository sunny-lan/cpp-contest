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
#include <stack>
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

#define MAXN 1000001

ll psa[MAXN + 1];

int main() {
	int n, q; scan(n); scan(q);
	stack<pii> s;
	s.push({ -1,-1 });
	for (int i = 0; i < n; i++) {
		int h; scan(h);
		while (s.top().second > h) {
			int idx = s.top().first,
				lvl = s.top().second;
			s.pop();
			psa[lvl + 1] += (idx - s.top().first)*(ll)(i - idx);
		}
		s.push({ i,h });
	}

	while (s.size() > 1) {
		int idx = s.top().first,
			lvl = s.top().second;
		s.pop();
		psa[lvl + 1] += (idx - s.top().first)*(ll)(n - idx);
	}

	for (int i = 0; i <= MAXN; i++)
		psa[i + 1] += psa[i];

	for (int i = 0; i < q; i++) {
		int x, y; scan(x); scan(y);
		printf("%lld\n", psa[y + 1] - psa[x]);
	}
	cin >> n;
}