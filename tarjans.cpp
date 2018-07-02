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

vector<int> adj[MAXN];
int gidx = 0;
int disc[MAXN];
int low[MAXN];
stack<int> S;
bool ins[MAXN];
vector<vector<int>> comps;
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
		vector<int> scc;
		int w;
		do {
			 w = S.top(); S.pop();
			ins[w] = false;
			scc.push_back(w);
		} while (w != v);
		comps.push_back(scc);
	}
}

void tarjan(int n) {
	memset(disc, -1, sizeof disc);
	for (int i = 0; i < n; i++)
		if (disc[i] == -1)
			dfs(i);
}

int main() {

}