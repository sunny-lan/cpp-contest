#include <iostream>
#include <vector>

using namespace std;
#define scan(x) do { while ((x = getchar())<'0'); for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0'); } while (0)
char _;

#define MOD 1000000007
#define MAXN 200010

typedef long long ll;

ll bit[MAXN];
int n;

void update(int p, ll v) {
	for (int x = p; x <= MAXN; x += x&-x)
		bit[x] += v;
}

ll query(int p) {
	ll res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int parent[MAXN];
vector<int> adj[MAXN];

int ord[MAXN];

ll ans[MAXN];

void dfs(int i) {
	ll before = query(ord[i]);
	for (int neigh : adj[i])
		if (neigh != parent[i])
			dfs(neigh);
	ans[i] = (query(ord[i]) - before + 1+MOD)%MOD;
	update(ord[i], ans[i]);
}

int main() {
	cin >> n;
	int root = -9999;
	for (int i = 0; i < n; i++) {
		scan(parent[i]);
		--parent[i];
		if (parent[i] == -1) root = i;
		else adj[parent[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		int tmp;
		scan(tmp);
		tmp--;
		ord[tmp] = i;
	}

	dfs(root);

	for (int i = 0; i < n; i++)
		cout << ans[i] % MOD << " ";
	cout << endl;
	cin >> n;
}