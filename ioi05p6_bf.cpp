#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 101

vector<pii> chi[MAXN];
int w[MAXN];

bool v[MAXN];
int dfs(int i = 0, int d = 0) {
	int tot = d * w[i];
	if(v[i])
		d = 0, tot = 0;
	for(pii k : chi[i])
		tot += dfs(k.f, d + k.s);
	return tot;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		int v, d;
		scanf("%d%d%d", &w[i], &v, &d);
		chi[v].push_back({i, d});
	}
	int mini = INT_MAX;
	for(int i = 0; i < 1 << n; i++) {
		int cnt = 0;
		for(int j = 0; j < n; j++)
			if((i >> j) & 1)
				v[j + 1] = true, cnt++;
			else
				v[j + 1] = false;
		if(cnt == k)
			mini = min(mini, dfs());
	}
	printf("%d\n", mini);
}
