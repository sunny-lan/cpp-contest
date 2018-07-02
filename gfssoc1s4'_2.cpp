#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
typedef long long ll;

#define MAXN 252

ll bit[MAXN][MAXN][MAXN];
int n;
int v[MAXN][MAXN][MAXN];

void update(int x, int y, int z, int v) {
	for (int xIdx = x; xIdx <= n; xIdx += xIdx & -xIdx)
		for (int yIdx = y; yIdx <= n; yIdx += yIdx & -yIdx)
			for (int zIdx = z; zIdx <= n; zIdx += zIdx & -zIdx)
				bit[xIdx][yIdx][zIdx] += v;
}

ll query(int x, int y, int z) {
	ll res = 0;
	for (int xIdx = x; xIdx > 0; xIdx -= xIdx & -xIdx)
		for (int yIdx = y; yIdx > 0; yIdx -= yIdx & -yIdx)
			for (int zIdx = z; zIdx > 0; zIdx -= zIdx & -zIdx)
				res += bit[xIdx][yIdx][zIdx];
	return res;
}

ll q2(int x2, int y2, int z2, int x1, int y1, int z1) {
	return query(x2, y2, z2)
		- query(x1, y2, z2) - query(x2, y1, z2) - query(x2, y2, z1)
		+ query(x2, y1, z1) + query(x1, y2, z1) + query(x1, y1, z2)
		- query(x1, y1, z1);
}


int main() {
	memset(bit, 0, sizeof bit);
	memset(v, 0, sizeof v);
	int q; scanf("%d %d", &n, &q);
	ll s = 0;
	for (int i = 0; i < q; i++) {
		char op; scanf(" %c", &op);
		if (op == 'C') {
			int x, y, z, l;
			scanf("%d %d %d %d", &x, &y, &z, &l);
			update(x, y, z, l - v[x][y][z]);
			v[x][y][z] = l;
		}
		else {
			int x1, y1, z1, x2, y2, z2;
			scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			s += q2(x2, y2, z2, x1 - 1, y1 - 1, z1 - 1);
		}
	}
	cout << s << endl;
	cin >> n;
}