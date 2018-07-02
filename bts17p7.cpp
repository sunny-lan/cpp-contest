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

#define MAXN 1000

vector<int> adj[MAXN];

int *d;
int dist[MAXN][MAXN];

int *p;
int src[MAXN][MAXN];

void dfs(int i, int j, int l) {
	//cout << i << " " << j << endl;
	d[i] = l;
	p[i] = j;
	for (int neigh : adj[i]) if (neigh != j)
		dfs(neigh, i, l + 1);
}

int cnt[MAXN];

int main() {
	int n, s; scan(n); scan(s);
	for (int i = 0; i < n-1; i++) {
		int x, y; scan(x); scan(y);
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		d = dist[i], p = src[i];
		dfs(i, -1, 0);
	}


	for (int i = 0; i < s; i++) {
		int a, b, t; scan(a); scan(b); scan(t);
		a--, b--, t--;
		int ptr = a;
		while (ptr != -1) {
			cnt[ptr] += dist[t][ptr];
			ptr = src[b][ptr];
		}
	}

	for (int i = 0; i < n; i++)
		cout << cnt[i] << " ";
	cout << endl;

	cin >> n;
}