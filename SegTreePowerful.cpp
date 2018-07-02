#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//template begin
//NOTE: indices are indexed at 0, in the form [l, r)
#define MAXN 100000
int n;  // array size
 
template <typename T>
void build(T *t, T(*combiner)(T, T)) {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = combiner(t[i << 1], t[i << 1 | 1]);
}

template <typename T>
void modify(int p, T value, T *t, T(*combiner)(T, T)) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

template <typename T>
T query(int l, int r, T *t, T(*combiner)(T, T)) {  // sum on interval [l, r)
	T res;
	bool flag = false; //prevents needing identity
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) (res = flag ? combiner(res, t[l++]) : t[l++]), flag = true;
		if (r & 1) (res = flag ? combiner(res, t[--r]) : t[--r]), flag = true;
	}
	return res;
}
//template end

int add(int a, int b) {
	return a + b;
}


int tree[2 * MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", tree + n + i);
		build(tree, add);
	modify(0, 1, tree, add);
	printf("%d\n", query(3, 11, tree, add));
	return 0;
}