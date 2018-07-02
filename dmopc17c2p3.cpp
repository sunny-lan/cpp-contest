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

#define MAXN 200000
#define INF 1000000

vector<int> adj[MAXN];
bool rab[MAXN];
int dst;

pair<int,bool> f(int i, int j) {
	int mini = rab[i] ? 0 : INF;
	bool content = false;
	for (int neigh : adj[i])if (neigh != j) {
		pii alt = f(neigh, i);
		content |= alt.second;
		int res = alt.first;
		if (!alt.second)res++;
		mini = min(mini, res);
	}
	if (i == dst)content=true;
	return{ mini,content };
}

int main() {
	int n, r; scan(n); scan(r);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < r; i++) {
		int x; scan(x);
		x--;
		rab[x] = true;
	}

	int x; scan(x); scan(dst);
	x--, dst--;

	printf("%d\n", f(x, -1));

	cin >> n;
}