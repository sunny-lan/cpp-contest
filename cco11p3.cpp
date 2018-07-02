#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000

bitset<MAXN> adj[MAXN];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a][b] = 1;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			if((adj[i]&adj[j]).count() > 1) {
				printf("NO\n");
				return 0;
			}

	printf("YES\n");
}
