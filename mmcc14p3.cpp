#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 5000

int n, s;
vector<int> adj[MAXN];
int p[MAXN];
int h[MAXN];
bool covered[MAXN];
int ptr[MAXN];
bool pred(int a, int b) {
	return h[a] > h[b];
}

int maxh = 0;
void dfs(int i, int j) {
	p[i] = j;
	for (int neigh : adj[i])if (neigh != j)
		maxh = max(maxh, h[neigh] = h[i] + 1),
		dfs(neigh, i);
}

void fill(int i, int dist, int j) {
	if (dist < 0)return;
	covered[i] = true;
	for (int neigh : adj[i])if(neigh!=j)
		fill(neigh, dist - 1, i);
}

bool canCover(int d) {
	int ctr = 0;
	for (int i = 0; i < n; i++) {
		if (ctr == s)break;
		int idx = ptr[i];
		if (covered[idx])continue;
		for (int j = 0; j < d; j++) idx = p[idx];
		fill(idx, d, -1);
		ctr++;
	}
	bool ret = true;
	for (int i = 0; i < n; i++) {
		if (!covered[i])
			ret = false;
		covered[i] = false;
	}
	return ret;
}

int main() {
	scan(n); scan(s);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scan(u); scan(v);
		u--, v--;
		adj[u].push_back(v), adj[v].push_back(u);
		ptr[i] = i;
	}
	ptr[n - 1] = n - 1;
	dfs(0, 0);
	sort(ptr, ptr + n, pred);
	for (int i = 0; i <= maxh; i++)
		if (canCover(i))
		{
			printf("%d\n", i);
			break;
		}
	cin >> n;
}