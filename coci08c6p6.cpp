#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

#define MAXM 1500
#define MAXN 100

int idx = 0;
int adj[MAXM][MAXM];
int flw[MAXM][MAXM];
void mkc(int a, int b, int c) {
	adj[a][b] = c;
}

int p[MAXM];
int bfs(int src, int dst) {
	memset(p, -1, sizeof p);
	queue<pii> q;
	q.push({src, INT_MAX});
	while(!q.empty()) {
		pii i = q.front();
		q.pop();
		if(i.f == dst)
			return i.s;
		for(int j = 0; j < idx; j++)
			if(p[j] == -1 && adj[i.f][j] > 0)
				p[j] = i.f, q.push({j, min(i.s, adj[i.f][j])});
	}
	return -1;
}

void karp(int src, int dst) {
	while(1) {
		int af = bfs(src, dst);
		if(af <= 0)
			break;
		int cur = dst;
		while(cur != src) {
			int par = p[cur];
			flw[par][cur] += af;
			adj[par][cur] -= af;
			adj[cur][par] += af;
			flw[cur][par] -= af;
			cur = par;
		}
	}
}

int chil[MAXN];
int pur[MAXM];
int a[MAXM], b[MAXM];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int src = idx++, dst = idx++;
	int tot = 0;
	for(int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		chil[i] = idx++;
		mkc(chil[i], dst, c);
		tot += c;
	}
	tot /= 2;
	for(int cp = 0; cp < m; cp++) {
		scanf("%d %d", &a[cp], &b[cp]);
		a[cp]--, b[cp]--;
		pur[cp] = idx++;
		mkc(src, pur[cp], 2);
		mkc(pur[cp], chil[a[cp]], INT_MAX);
		mkc(pur[cp], chil[b[cp]], INT_MAX);
	}
	for(int cp = m; cp < tot; cp++)
	{
		pur[cp] = idx++;
		mkc(src, pur[cp], 2);
		for(int i = 0; i < n; i++)
			mkc(pur[cp], chil[i], INT_MAX);
	}
	karp(src, dst);
	printf("%d\n", tot);
	for(int i = 0; i < m; i++)
		printf("%d %d %d\n", a[i] + 1, b[i] + 1, flw[pur[i]][chil[a[i]]]);
	for(int i = m; i < tot; i++) {
		int aa = -1, ba = -1;
		for(int j = 0; j < n; j++)
			if(flw[pur[i]][chil[j]] > 0) {
				if(aa == -1)
					aa = j;
				else {
					ba = j;
					break;
				}
			}
		if(ba == -1)
			ba = (aa + 1) % n;
		printf("%d %d %d\n", aa + 1, ba + 1, flw[pur[i]][chil[aa]]);
	}
}
