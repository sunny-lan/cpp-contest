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

#define MAXN 100000

vector<pii> adj[MAXN];
pair<pii, int> edges[MAXN * 2];
int marker[MAXN * 2];

int dst[MAXN];

void dfs(int i, int j, int d) {
	dst[i] = d;
	for (pii neigh : adj[i])if (neigh.first != j)
		dfs(neigh.first, i, d + neigh.second);
}

int main() {
	int n, m, x, y; scan(n); scan(m); scan(x); scan(y);
	x--, y--;
	bool mode = true;
	for (int i = 0; i < m; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		a--, b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		edges[i] = { {a,b},c };
		//if (c == 1) {
			if (a == x || b == x)
				marker[i] = 1;
			else if (a == y || b == y)
				marker[i] = 2;
			else if ((a == x && b == y) || (b == x && a == y))
				marker[i] = 3;
		//}
		//else mode = false;
	}
	if (m != n*(n - 1) / 2)
		mode = false;
	if (m == n - 1 && x == y) {
		dfs(x, -1, 0);
	}

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int f, l; scan(f); scan(l);
		l--;
		if (m == n - 1 && x == y) {
			if (f == 1)
				printf("%d\n", dst[l]);
			else
				printf("%d\n", min(dst[edges[l].first.first], dst[edges[l].first.second]));
		}
		else  {
			if (f == 1) {
				if (l == x || l == y)
					printf("-1\n");
				else
					printf("1\n");
			}
			else {
				if (marker[l] == 0)
					printf("1\n");
				else if (marker[l] == 1 || marker[l] == 2)
					printf("1\n");
				else if (marker[l] == 3)
					printf("0.5\n");
			}
		}
	}
}