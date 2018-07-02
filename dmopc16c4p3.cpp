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
#include <set>
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

#define MAXK 100
#define MAXN 100000

set<pii> stands[MAXK];

int d[MAXN];

int main() {
	int n, s; scan(n); scan(s);
	for (int i = 0; i < n; i++)
		scan(d[i]);

	for (int i = 0; i < s; i++) {
		int s, a; scan(s); scan(a);
		s--;
		stands[a].insert({ d[s], s });
	}

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		char op; int x; scanf(" %c %d", &op, &x);
		if (op == 'Q') {
			if (stands[x].size() == 0) printf("-1\n");
			else printf("%d\n", (*stands[x].begin()).second+1);
			continue;
		}
		int k; scan(k);
		x--;
		pii curr = { d[x], x };
		if (op == 'A')
			stands[k].insert(curr);

		if (op == 'S')
			stands[k].erase(curr);

		if (op == 'E') {
			for (int i = 0; i < MAXK; i++)
				stands[i].erase(curr);
			d[x] = k;
		}
	}
	cin >> n;

}