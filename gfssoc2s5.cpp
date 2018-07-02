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
#include <stack>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 500000
int v2[MAXN];

vector<int> adj[MAXN];
int gidx = 0;
int disc[MAXN];
int low[MAXN];
stack<int> S;
bool ins[MAXN];
int glbl=0;
int lbl[MAXN];
int cnt[MAXN];
void dfs(int v) {
	disc[v] = gidx;
	low[v] = gidx;
	gidx++;
	S.push(v);
	ins[v] = true;
	for (int w : adj[v]) {
		if (disc[w] == -1) {
			dfs(w);
			low[v] = min(low[v], low[w]);
		}
		else if (ins[w]) {
			low[v] = min(low[v], disc[w]);
		}
	}
	if (disc[v] == low[v]) {
		int w;
		do {
			w = S.top(); S.pop();
			ins[w] = false;
			lbl[w] = glbl;
			cnt[glbl] += v2[w];
		} while (w != v);
		glbl++;
	}
}

void tarjan(int n) {
	memset(disc, -1, sizeof disc);
	for (int i = 0; i < n; i++)
		if (disc[i] == -1)
			dfs(i);
}

#define MAXM 1500000
#define MOD 1000000007
pii e[MAXM];
vector<int> adj2[MAXN + 1];
int n, m;
pii dp[MAXN + 1][2];
pii ways(int i, int prv) {
	if (i == lbl[n - 1])
		return{ prv == 1 ? 0 : cnt[i], 1 };
	pii res = dp[i][prv];
	if (res.first != -1)return res;
	res = { 0,0 };
	for (int neigh : adj2[i])
	{
		pii r = ways(neigh, 0);
		if (r.first > res.first)
			res = r;
		else if (r.first == res.first)
			res.second += r.second;
		res.second %= MOD;
		if (prv != 1) {
			r = ways(neigh, 1);
			r.first += cnt[i];
			if (r.first > res.first)
				res = r;
			else if (r.first == res.first)
				res.second += r.second;
			res.second %= MOD;
		}
	}
	return dp[i][prv]=res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scan(n); scan(m);
	for (int i = 0; i < n; i++)
		scan(v2[i]);
	for (int i = 0; i < m; i++) {
		int a, b; scan(a); scan(b);
		a--, b--;
		e[i] = { a,b };
		adj[a].push_back(b);
	}
	tarjan(n);
	for (int i = 0; i < m; i++)
	{
		int a = lbl[e[i].first],
			b = lbl[e[i].second];
		if (a == b)continue;
		adj2[a].push_back(b);
	}
	pii dsfg = ways(lbl[0], 0);
	printf("%d %d\n", dsfg.first, dsfg.second);
	cin >> n;
}