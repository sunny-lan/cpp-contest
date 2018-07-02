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

#define MAXN 200010
int n, k;
int c[MAXN];

vector<int> adj[MAXN];

pii d(int i, int j, int dst) {
	int maxi = dst;
	int best=i;
	for (int neigh : adj[i]) {
		if (neigh == j)continue;
		pii r=d(neigh, i, dst + 1);
		if (r.first > maxi) {
			maxi = r.first;
			best = r.second;
		}
	}
	return{ maxi, best };
}

int c1 = -1;
int c2 = -1;

bool res = false;

void chk(int i, int j,int lvl) {
	if (lvl % 2 == 0) {
		if (c1 == -1)
			c1 = c[i];
		if (c1 != c[i])
			res = true;
	}
	else {
		if (c2 == -1)
			c2 = c[i];
		if (c2 != c[i])
			res = true;
	}
	for (int neigh : adj[i]) {
		if (neigh == j)continue;
		chk(neigh, i, lvl + 1);
	}
}

int main() {
	scan(n); scan(k);
	for (int i = 0; i < n; i++)
		scan(c[i]);

	for (int i = 0; i < n - 1; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int u = d(0, -1, 0).second;
	int v = d(u, -1, 0).first;

	if(v==n-1){
		chk(u, -1, 0);
		if (!res)
			v--;
	}

	printf("%d\n", v+1);
}