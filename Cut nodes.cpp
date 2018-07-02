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

#define MAXN 100000

vector<int> adj[MAXN];

bool cut[MAXN];
int disc[MAXN];
int low[MAXN];
bool visited[MAXN];
int time = 0;
void dfs(int i, int j=-1) {
	if (visited[i])return;
	visited[i] = true;
	//back edge to itself
	disc[i] = low[i] = ++time;
	int cnt = 0;
	for (int neigh : adj[i]) {
		if (visited[neigh]) {
			//subtree has already been visited
			if (neigh != j)
				low[i] = min(low[i], disc[neigh]);
		}
		else {
			cnt++;
			dfs(neigh, i); 
			//lowest reachable is lowest out of descendants
			low[i] = min(low[i], low[neigh]);
			if (j != -1 && low[neigh] >= disc[i])
				cut[i] = true;
		}
	}
	if (j == -1 && cnt > 1)
		cut[i] = true;
}

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int a, b; scan(a); scan(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		if (cut[i])
			printf("%d\n", i);
	cin >> n;
}