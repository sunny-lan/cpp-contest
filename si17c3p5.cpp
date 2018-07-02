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
typedef pair<int, char> pic;

#define MAXN 100010

vector<pic> adj[MAXN];

int sz[MAXN];
bool v[MAXN];
int centroid_dfs(int i, int j = -1)
{
	if (v[i])
		return 0;
	sz[i] = 1;
	for (pic neigh : adj[i])
		if (neigh.first != j)
			sz[i] += centroid_dfs(neigh.first, i);
	return sz[i];
}

int centroid(int i, int tsz, int j = -1) {
	for (pic neigh : adj[i])
		if (neigh.first != j && !v[neigh.first] && sz[neigh.first] * 2 > tsz)
			return centroid(neigh.first, tsz, i);
	return i;
}

ll tot = 0;
unordered_map<int, int> cnt;
vector<int> cur;

int  ct;
void dfs(int i, int off, int j)
{
	if (v[i])
		return;
	cur.push_back(off);
	tot += cnt[-off + 1] + cnt[-off - 1];
	if (j != ct && (off == 1 || off == -1))
		tot++;
	for (pic neigh : adj[i])
	{
		if (neigh.first == j)
			continue;
		if (neigh.second == 'r')
			dfs(neigh.first, off + 1, i);
		else
			dfs(neigh.first, off - 1, i);
	}
}

void calc(int i)
{
	if (v[i])return;
	i = centroid(i, centroid_dfs(i));
	v[i] = true;
	ct = i;
	cnt.clear();
	for (pic neigh : adj[i])
	{
		if (v[neigh.first])continue;
		cur.clear();
		if (neigh.second == 'r')
			dfs(neigh.first, 1, i);
		else
			dfs(neigh.first, -1, i);
		for (auto v : cur)
			cnt[v] ++;
	}
	for (pic sub : adj[i])
		calc(sub.first);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);
		a--, b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	calc(0);
	printf("%lld\n", tot);
	cin >> n;
}