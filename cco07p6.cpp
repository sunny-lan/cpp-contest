#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef pair<int, int> pii;

#define MAXN 1001

vector<int> adj[MAXN];

vector<pii> cut;
int disc[MAXN];
int low[MAXN];
bool visited[MAXN];
int vtime = 0;
void _cut_dfs(int i, int j = -1) {
	if (visited[i])return;
	visited[i] = true;
	disc[i] = low[i] = ++vtime;
	int cnt = 0;
	for (int neigh : adj[i]) {
		if (visited[neigh]) {
			if (neigh != j)
				low[i] = min(low[i], disc[neigh]);
		}
		else {
			cnt++;
			_cut_dfs(neigh, i);
			low[i] = min(low[i], low[neigh]);
			if (low[neigh] > disc[i])
				cut.push_back({ i, neigh });
		}
	}
}

void cutedges() {
	for (int i = 0; i<n; i++)if (!visited[i])_cut_dfs(i);
}

int n, r;
int deg[MAXN];
bool adj2[MAXN][MAXN];
int marker = 1;
int visited2[MAXN];
void dfs2(int i) {
	if (visited2[i])return;
	visited2[i] = marker;
	for (int j = 0; j < n; j++)if (adj2[i][j])
		dfs2(j);
}

int main() {
	 scan(n); scan(r);
	for (int i = 0; i < r; i++) {
		int v, w; scan(v); scan(w);
		--v, --w;
		adj[v].push_back(w);
		adj[w].push_back(v);
		adj2[v][w] = adj2[w][v] = true;
	}
	cutedges();
	for (pii edj : cut) {
		int v = edj.first, w = edj.second;
		adj2[v][w] = adj2[w][v] = false;
	}

	memset(visited2, false, sizeof visited2);
	for (int i = 0; i < n; i++) if (!visited2[i])
		dfs2(i), marker++;

	for(pii edj:cut)  {
		int v = edj.first, w = edj.second;
		deg[visited2[v]]++;
		deg[visited2[w]]++;
	}

	int cnt = 0;
	for (int i = 0; i <= n; i++)if (deg[i] == 1)
		cnt++;

	cout << (cnt + 1) / 2 << endl;
}