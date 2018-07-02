#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100000

void update(int p, int v, vector<int> &bit) {
	for(; p < bit.size(); p += p & -p)
		bit[p] = max(bit[p], v);
}

int query(int p, vector<int> &bit) {
	int res = 0;
	for(; p > 0; p -= p & -p)
		res = max(res, bit[p]);
	return res;
}

map<int, int> bs[MAXN];
pair<pii, int> edj[MAXN];
vector<int> bit[MAXN];
vector<int> ew[MAXN];
unordered_map<int, int> ord[MAXN];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		a--, b--;
		edj[i] = {{a, b}, w};
		ew[b].push_back(w);
		ew[a].push_back(w);
	}
	for(int i = 0; i < n; i++) {
		sort(ew[i].begin(), ew[i].end());
		ew[i].resize(unique(ew[i].begin(), ew[i].end())-ew[i].begin());
//		cout << i<<": "<<endl;
		for(int j = 0; j < ew[i].size(); j++) {
			ord[i][ew[i][j]] = j + 1;
//			cout << " "<<ew[i][j]<<" -> "<<j+1<<endl;
			bit[i].push_back(0);
		}
		bit[i].push_back(0);
	}
	int maxi = 0;
	for(int i = 0; i < m; i++) {
		int a = edj[i].f.f, b = edj[i].f.s, w = edj[i].s;
		int wa = ord[a][w], wb = ord[b][w];
		int bst = query(wa-1, bit[a]) + 1;
		maxi = max(bst, maxi);
		update(wb, bst, bit[b]);
	}
	printf("%d", maxi);
}
