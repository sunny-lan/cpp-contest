#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 100010

int bit[MAXN];

void update(int p, int v) {
	for(int i = p; i < MAXN; i += i & -i)
		bit[i] = max(bit[i], v);
}

int query(int p) {
	int res = 0;
	for(int i = p; i > 0; i -= i & -i)
		res = max(res, bit[i]);
	return res;
}

pii kust[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &kust[i].first, &kust[i].second);
	sort(kust, kust + n);
	for(int i = 0; i < n;) {
		vector<pii> e;
		int tmp = i;
		while(tmp < n && kust[tmp].first == kust[i].first)
			e.push_back({kust[tmp].second, query(kust[tmp].second - 1) + 1}), tmp++;
		for(pii kust : e)
			update(kust.first, kust.second);
		i = tmp;
	}
	printf("%d\n", query(MAXN));
}
