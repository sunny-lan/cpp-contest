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
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 200010

vector<pii> adj[MAXN];

ll du[MAXN];
bool inq[MAXN];

int main() {
	ll n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++)
	{
		int a, b, p; scan(a); scan(b); scan(p);
		a--, b--;
		adj[a].push_back({ b,p });
		adj[b].push_back({ a,p });
	}

	du[0] = INT_MAX;

	priority_queue<pii> q;
	q.push({ INT_MAX, 0 });
	inq[0] = true;
	while (!q.empty()) {
		pii curr = q.top(); q.pop();
		ll i = curr.second;
		inq[i] = false;
		for (pii neigh : adj[i]) {
			ll j = neigh.first,
				c = neigh.second;
			ll alt = min(c, du[i]);
			if (alt > du[j]) {
				du[j] = alt;
				if (inq[j])continue;
				q.push({ alt, j });
				inq[j] = true;
			}
		}
	}

	du[0] = 0;
	for (int i = 0; i < n; i++)
		printf("%lld\n", du[i]);
}