#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int n;  // array size

template <typename NUM>
void build(NUM *t, NUM(*combiner)(NUM, NUM)) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = combiner(t[i << 1], t[i << 1 | 1]);
}

template <typename NUM>
void modify(int p, NUM value, NUM *t, NUM(*combiner)(NUM, NUM)) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

template <typename NUM>
NUM query(int l, int r, NUM *t, NUM(*combiner)(NUM, NUM)) {  // sum on interval [l, r)
	NUM res;
	bool flag = false;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) (res = flag ? combiner(res, t[l++]) : t[l++]), flag = true;
		if (r & 1) (res = flag ? combiner(res, t[--r]) : t[--r]), flag = true;
	}
	return res;
}

int minT[MAXN * 2];
int gcdT[MAXN * 2];
pair<int, int> gcdCntT[MAXN * 2];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

pair<int, int> gcdCnt(pair<int, int> a, pair<int, int> b) {
	int newGcd = gcd(a.first, b.first);
	int total = 0;
	if (a.first == newGcd)
		total += a.second;
	if (b.first == newGcd)
		total += b.second;
	return{ newGcd, total };
}

int minWrap(int a, int b) {
	return min(a, b);
}


int main() {
	int m; scan(n); scan(m);
	for (int i = n; i < 2 * n; i++) {
		int x; scan(x);
		minT[i] = x;
		gcdT[i] = x;
		gcdCntT[i] = { x, 1 };
	}
	build(minT, minWrap);
	build(gcdT, gcd);
	build(gcdCntT, gcdCnt);

	for (int i = 0; i < m; i++) {
		char op; int a, b; scanf(" %c %d %d", &op, &a, &b);
		if (op == 'C')
		{
			modify(--a, b, minT, minWrap);
			modify(a, b, gcdT, gcd);
			modify(a, { b , 1 }, gcdCntT, gcdCnt);
		}
		else if (op == 'M') {
			printf("%d\n", query(--a, b, minT, minWrap));
		}
		else if (op == 'G') {
			printf("%d\n", query(--a, b, gcdT, gcd));
		}
		else {
			printf("%d\n", query(--a, b, gcdCntT, gcdCnt).second);
		}
	}
}