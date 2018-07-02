#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

vector<int> children[MAXN];
int order[MAXN];

int cnt = 0;

void dfs(int i) {
	cout << "node " << i+1 << ", cnt " << cnt << endl;
	order[i] = cnt;
	for (int child : children[i]) {
		cnt++;
		dfs(child);
	}
	cnt++;
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int c; scan(c);
		for (int j = 0; j < c; j++) {
			int k; scan(k);
			children[i].push_back(--k);
		}
	}

	dfs(0);

	cout << cnt << endl;

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int u, v; scan(u); scan(v);
		u = order[--u], v = order[--v];
		if (v < u)
			v += cnt;
		printf("%d\n", v - u);
	}

	scan(n);
}