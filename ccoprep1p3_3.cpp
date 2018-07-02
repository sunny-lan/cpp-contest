
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100001

int p[MAXN];
ordered_set<int> r[MAXN];
int sz[MAXN];

int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	int smaller = find(x);
	int bigger = find(y);
	if (smaller == bigger)return;
	if (sz[smaller] > sz[bigger]) {
		int tmp = smaller;
		smaller = bigger;
		bigger = tmp;
	}

	for (int i = 0; i < sz[smaller]; i++)
		r[bigger].insert(*r[smaller].find_by_order(0)),
		r[smaller].erase(r[smaller].find_by_order(0));

	sz[bigger] += sz[smaller];
	sz[smaller] = 0;

	p[smaller] = bigger;
}

int ord[MAXN];

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		int k; scan(k);
		p[i] = i;
		sz[i] = 1;
		r[i].insert(k);
		ord[k] = i+1;
	}

	for (int i = 0; i < m; i++) {
		int x, y; scan(x); scan(y);
		x--, y--;
		merge(x, y);
	}

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		char op; int x, y; scanf(" %c %d %d", &op, &x, &y);
		x--, y--;
		if (op == 'B')
			merge(x, y);
		else {
			if (y>sz[find(x)])
				printf("-1\n");
			else
				printf("%d\n", ord[*r[find(x)].find_by_order(y)]);
		}
	}
}