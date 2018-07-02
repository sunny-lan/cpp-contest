#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef long long ll;

#define MAXN 100011

ll bit1[MAXN], bit2[MAXN];

void update(int p, int v, ll *bit) {
	for (int i = p; i < MAXN; i += i&-i)
		bit[i] += v;
}

ll query(int p, ll *bit) {
	ll res = 0;
	for (int i = p; i > 0; i -= i&-i)
		res += bit[i];
	return res;
}

int val[MAXN];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
		update(i, val[i], bit1);
		update(val[i], 1, bit2);
	}

	for (int i = 0; i < m; i++) {
		char op; scanf(" %c", &op);
		if (op == 'C') {
			int x, v; scanf("%d %d", &x, &v);
			update(x, v - val[x], bit1);
			update(val[x], -1, bit2);
			update(v, 1, bit2);
			val[x] = v;
		}
		else if (op == 'S') {
			int l, r; scanf("%d %d", &l, &r);
			printf("%lld\n", query(r, bit1) - query(l - 1, bit1));
		}
		else {
			int v; scanf("%d", &v);
			printf("%lld\n", query(v, bit2));
		}
	}

	cin >> n;
}