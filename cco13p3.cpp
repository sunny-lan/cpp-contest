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
typedef pair<int, ll> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 400000

vector<int> adj[MAXN];

ll diam = 0, dcnt = 0;

pii dfs(int i, int j) {
	ll maxi = 0, cnt = 1;

	for (int neigh : adj[i])if (neigh != j) {
		pii alt = dfs(neigh, i);
		ll len = alt.first + 1;
		ll altdiam = len + maxi + 1;
		if (altdiam >= diam) {
			ll diamcnt=alt.second*cnt;
			if (altdiam > diam)
				dcnt = 0;
			diam = altdiam;
			dcnt += diamcnt;
		}
		if (len > maxi)
			maxi = len, cnt = alt.second;
		else if (len == maxi)
			cnt += alt.second;
	}

	return{ maxi, cnt };
}

int main() {
	int n; scan(n);
	for (int r = 0; r < n - 1; r++) {
		int i, j; scan(i); scan(j);
		i--, --j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	dfs(0, -1);

	printf("%lld %lld\n", diam, dcnt);
}