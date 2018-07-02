#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000001

template <typename T>
void modify(int p, T value, T *t, T(*combiner)(T, T)) {  // set value at position p
	for (t[p += MAXN] = value; p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

template <typename T>
T query(int l, int r, T *t, T(*combiner)(T, T)) {  // sum on interval [l, r)
	T res = 0;
	for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = combiner(res, t[l++]);
		if (r & 1) res = combiner(res, t[--r]);
	}
	return res;
}
//template end

int maxF(int a, int b) { return max(a, b); }

int tree[2 * MAXN];
int ord[MAXN];
int b[MAXN];

int main() {
	memset(ord, -1, sizeof ord);

	int n; scan(n);
	for (int i = 0; i < n; i++) { int a; scan(a); ord[a] = i; }
	int m; scan(m);
	for (int i = 0; i < m; i++) { scan(b[i]); b[i] = ord[b[i]]; }

	for (int i = 0; i < m; i++) if (b[i] != -1)
		modify(b[i], query(0, b[i], tree, maxF) + 1, tree, maxF);

	printf("%d\n", query(0, MAXN, tree, maxF));
}