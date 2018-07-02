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
#include <stack>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 500000

int p[MAXN];
int r[MAXN];
int s[MAXN];
stack<pii> last;

int find(int x) {
	if (p[x] == x)return x;
	return find(p[x]);
}

void Init(int N) {
	for (int i = 0; i < N; i++) {
		p[i] = i;
		s[i] = 1;
	}
}

void AddEdge(int U, int V) {
	U--, V--;
	int pu = find(U),
		pv = find(V);
	if (pu == pv)
	{
		last.push({-1,-1});
		return;
	}
	if (r[pu] < r[pv]) {
		p[pu] = pv;
		last.push({ pu, r[pv] });
		r[pv] = max(r[pv], r[pu] + 1);
		s[pv] += s[pu];
	}
	else {
		p[pv] = pu;
		last.push({ pv, r[pu] });
		r[pu] = max(r[pu], r[pv] + 1);
		s[pu] += s[pv];
	}
}

void RemoveLastEdge() {
	pii tmp = last.top(); last.pop();
	int u = tmp.first;
	if (u == -1)return;
	int pu = p[u];
	r[pu] = tmp.second;
	s[pu] -= s[u];
	p[u] = u;
}

int GetSize(int U) {
	U--;
	return s[find(U)];
}