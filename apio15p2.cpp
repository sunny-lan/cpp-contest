#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 30000
#define MAXS 180

struct edj {
	int a, cost;
};

bool doge[MAXS][MAXN];

vector<edj> adj[MAXN];
int du[MAXN];
bool inq[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> q;

void ins(int j, int alt) {
	if(alt < du[j]) {
		du[j] = alt;
		if(!inq[j]) {
			q.push({alt, j});
			inq[j] = true;
		}
	}
}

int main() {
	memset(du, 0x3f, sizeof du);
	int n, m;
	scanf("%d %d", &n, &m);
	int lim = (int)floor(sqrt(n)) + 1;
	int src, dst;
	for(int i = 0; i < m; i++) {
		int b, p;
		scanf("%d %d", &b, &p);
		if(i == 0)
			src = b;
		if(i == 1)
			dst = b;
		if(p < lim)
			doge[p][b] = true;
		else {
			for(int j = b - p; j >= 0; j -= p)
				adj[b].push_back({j, (b - j) / p});
			for(int j = b + p; j < n; j += p)
				adj[b].push_back({j, (j - b) / p});
		}
	}

	for(int p = 0; p < lim; p++)
		for(int i = 0; i < n; i++)
			if(doge[p][i]) {
				for(int j = i - p; j >= 0; j -= p) {
					adj[i].push_back({j, (i - j) / p});
					if(doge[p][j])
						break;
				}
				for(int j = i + p; j < n; j += p) {
					adj[i].push_back({j, (j - i) / p});
					if(doge[p][j])
						break;
				}
			}

	q.push({0, src});
	du[src] = 0;
	while(!q.empty()) {
		int i = q.top().second;
		q.pop();
		inq[i] = false;
		for(edj e : adj[i])
			ins(e.a, du[i] + e.cost);
	}

	if(du[dst] >= 0x3f3f3f3f)
		du[dst] = -1;
	printf("%d\n", du[dst]);
}
