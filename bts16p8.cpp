#include <iostream>
#include <algorithm>

using namespace std;

#define combiner(a,b) max(a,b)
#define identity 0
#define MAXN 1000000

int n;  // array size
int t[2 * MAXN];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = combiner(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = identity;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = combiner(res, t[l++]);
		if (r & 1) res = combiner(res, t[--r]);
	}
	return res;
}
