#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000

int p[MAXN];
int f(int x) {
	if(p[x] == x)
		return x;
	return p[x] = f(p[x]);
}

set<int> v[MAXN];
int sz[MAXN];
int ans[MAXN];
int mrg(int x, int y) {
	int px = f(x), py = f(y);
	if(px == py)
		return INT_MAX;
	if(sz[px] > sz[py])
		swap(px, py);
	for(int i : v[px]) {
		auto nxt = v[py].lower_bound(i);
		if(nxt != v[py].end())
			ans[py] = min(ans[py], abs(*nxt - i));
		if(nxt != v[py].begin())
			ans[py] = min(ans[py], abs(*prev(nxt) - i));
	}
	for(int i : v[px])
		v[py].insert(i);
	ans[py] = min(ans[py], ans[px]);
	sz[py] += sz[px];
	sz[px] = 0;
	p[px] = py;
	return ans[py];
}

vector<int> chil[MAXN];
int res[MAXN];
int aa[MAXN];
void dfs(int i = 0) {
	res[i] = INT_MAX;
	if(chil[i].size() == 0)
		aa[i] = 1;
	for(int k : chil[i])
		dfs(k), res[i] = min(res[i], mrg(i, k)), aa[i] += aa[k];
}

int main() {
	memset(ans, 0x3f, sizeof ans);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++) {
		int pp;
		scanf("%d", &pp);
		pp--;
		chil[pp].push_back(i);
		p[i] = i;
	}
	for(int j = n - m; j < n; j++) {
		int x;
		scanf("%d", &x);
		v[j].insert(x);
		sz[j] = 1;
	}
	dfs();
	for(int i = 0; i < n - m; i++)
		printf("%d ", aa[i] == 1 ? INT_MAX : res[i]);
	printf("\n");
}
