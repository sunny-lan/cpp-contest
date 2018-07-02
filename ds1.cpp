#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAXN 100005

typedef long long ull;

int v[MAXN];
ull bit1[MAXN];
ull bit2[MAXN];
int n;

void update(int p, ull v) {
	//stores the current node to update
	int curr = p;

	//while node is in range
	while (curr <= n) {
		//update the node
		bit[curr] += v;

		//move up one node (aka add least significant set bit to node #)
		curr += curr & -curr;
	}
}

void update(int p, ull v, ull oldv) {
	int curr = p;
	while (curr <= n) {
		bit[curr] -= oldv;
		bit[curr] += v;
		curr += curr & -curr;
	}
}


ull query(int p) {
	ull res = 0;
	while (p > 0) {
		res += bit[p];
		p ^= p & -p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	int q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		bit = bit1, update(i, v[i]);
		bit = bit2, update(v[i], 1);
	}
	for (int i = 0; i < q; i++) {
		char op; int p;
		scanf(" %c %d", &op, &p);
		if (op == 'C') {
			int old = v[p];
			scanf("%d", &v[p]);
			bit = bit2, update(old, 1);
			bit = bit1, update(p, v[p], old);
			bit = bit2, update(v[p] , 1);
		}
		else if (op == 'S') {
			int r;
			scanf("%d", &r);
			bit = bit1;
			printf("%lld\n", query(r) - query(p - 1));
		}
		else {
			bit = bit2;
			printf("%lld\n", query(p ));
		}
	}
}