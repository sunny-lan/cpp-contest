#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1000
#define MAXM 10010

vector<pair<int, pii>> adj[MAXN];
int gk;
bool visited[MAXN];
void dfs(int i) {
	if (visited[i])return;
	visited[i] = true;
	for (auto edge : adj[i]) {
		pii rng = edge.second;
		if (rng.first <= gk && gk <= rng.second)
			dfs(edge.first);
	}
}

int main() {
	int n, m, k; scan(n); scan(m); scan(k);
	int s, t; scan(s); scan(t);
	s--, t--;
	vector<int> evts;
	for (int i = 0; i < m; i++) {
		int a, b, c, d; scan(a); scan(b);
		a--, b--; scan(c); scan(d);
		adj[a].push_back({ b,{c,d} });
		evts.push_back( c);
		evts.push_back(d+1);
	}
	evts.push_back(k+1);
	evts.push_back(1);
	sort(evts.begin(), evts.end());
	auto it = unique(evts.begin(), evts.end());
	evts.resize(distance(evts.begin(), it));
	int tot = 0;
	for (int i = 0; i < evts.size()-1;i++) {
		memset(visited, false, sizeof visited);
		gk = evts[i];
		dfs(s);
		if (visited[t])
			tot += evts[i + 1] - evts[i];
	}
	printf("%d\n", tot);
	cin >> n;
}