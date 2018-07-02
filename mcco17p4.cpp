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

int t[MAXN];

vector<int> adj[MAXN];
int _deg[MAXN];
int deg[MAXN];
int n, m;

int f(int s) {
	queue<int> q[2];
	q[0] = queue<int>();
	q[1] = queue<int>();
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			q[t[i]].push(i);

	int cnt = 0;
	
	while (!q[s].empty()) {
		while (!q[s].empty()) {
			int i = q[s].front(); q[s].pop();
			for (int j : adj[i]) {
				if (deg[j] == 0)continue;
				deg[j]--;
				if (deg[j] == 0)
					q[t[j]].push(j);
			}
		}
		s = (~s) & 1;
		if (!q[s].empty())
			cnt++;
	}

	if (!q[0].empty() || !q[1].empty())
		cnt = INT_MAX;

	return cnt;
}

int main() {

	scan(n); scan(m);
	for (int i = 0; i < n; i++)
		scan(t[i]);

	for (int i = 0; i < m; i++) {
		int a,b; scan(a); scan(b);
		adj[b].push_back(a);
		_deg[a]++;
	}

	//printf("\n");

	memcpy(deg, _deg, sizeof deg);
	int r1 = f(0);

	//printf("\n");

	memcpy(deg, _deg, sizeof deg);
	int r2 = f(1);

	printf("%d\n", min(r1, r2));

	cin >> n;
}