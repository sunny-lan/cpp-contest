#include <iostream>

using namespace std;

//template parameters
#define MAXN 100000
#define NUM int

//template begin
NUM bit[MAXN];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y < MAXN; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

//not sure if works
void construct(NUM *val) {
	for (int i = 0; i <= n; i++) {
		bit[i] += val[i];
		bit[i + (i&-i)] += bit[i];
	}
}

//3d rectangular prism query
//NUM q2(int x1, int y1, int z1, int x2, int y2, int z2) {
//	return query(x2, y2, z2)
//		- query(x1, y2, z2) - query(x2, y1, z2) - query(x2, y2, z1)
//		+ query(x2, y1, z1) + query(x1, y2, z1) + query(x1, y1, z2)
//		- query(x1, y1, z1);
//}
//template end

int main() {
	int q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int op, p;
		cin >> op >> p;
		if (op == 1) {
			int v;
			cin >> v;
			update(p, v);
		}
		else {
			cout << query(p) << endl;
		}
	}
}