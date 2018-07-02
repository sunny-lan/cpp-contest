#include <bits/stdc++.h>
using namespace std;

typedef double ll;
typedef pair<int, double> pii;
typedef pair<int, double> pil;
#define f first
#define s second

#define MAXN 200000

int n, c, kk;
int vv[MAXN];
vector<int> s[MAXN];
bool pred(int a, int b) {
	return vv[a] < vv[b];
}
vector<pii> adj[MAXN];
ll du[MAXN];
bool v[MAXN];
int nn;
void dijk() {
	for(int i = 0; i < nn; i++)
		du[i] = INFINITY;
	memset(v, false, sizeof v);
	priority_queue<pil> q;
	q.push({0, 0});
	du[0] = 0;
	while(!q.empty()) {
		int i = q.top().s;
		q.pop();
		v[i] = true;
		for(pii k : adj[i])
			if(!v[k.f]) {
				ll alt = du[i] + k.s;
				if(alt < du[k.f])
					du[k.f] = alt, q.push({-alt, k.f});
			}
	}
}


void proc(vector<int> &f, int l, int r) {
	if(r - l < 2)
		return;
	int mid = (l + r) / 2;
	double mp = ((r - l) % 2) ? vv[f[mid]] : ((vv[f[mid]] + vv[f[mid - 1]]) / 2.0);
	int a = nn++;
	for(int i = l; i < r; i++) {
		adj[f[i]].push_back({a, abs(vv[f[i]] - mp) + kk / 2.0});
		adj[a].push_back({f[i], abs(vv[f[i]] - mp) + kk / 2.0});
	}
	proc(f, l, mid), proc(f, mid + ((r - l) % 2), r);
}

int main() {
	scanf("%d%d%d", &n, &c, &kk);
	nn = n;
	for(int i = 0; i < n; i++)
		scanf("%d", &vv[i]);
	for(int i = 0; i < n; i++) {
		int ci;
		scanf("%d", &ci);
		for(int j = 0; j < ci; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			s[x].push_back(i);
		}
	}
	for(int i = 0; i < c; i++)
	{
		sort(s[i].begin(), s[i].end(), pred);
		if(kk)
			proc(s[i], 0, s[i].size());
		else {
			for(int j = 1; j < s[i].size(); j++) {
				int cst = vv[s[i][j]] - vv[s[i][j - 1]];
				adj[s[i][j]].push_back({s[i][j - 1], cst});
				adj[s[i][j - 1]].push_back({s[i][j], cst});
			}
		}
	}
	dijk();
	for(int i = 0; i < n; i++)
		if(du[i] == INFINITY)
			printf("-1\n");
		else
			printf("%.0lf\n", du[i]);
}
