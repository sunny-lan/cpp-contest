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

#define MAXN 1000000

int n;

template <typename NUM>
void modify(int p, NUM value, NUM *t, NUM(*combiner)(NUM, NUM)) {  // set value at position p
	p += n;
	for (t[p] = combiner(value, t[p]); p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

#define IDENTITY 0

template <typename NUM>
NUM query(int l, int r, NUM *t, NUM(*combiner)(NUM, NUM)) {  // sum on interval [l, r)
	NUM res = IDENTITY;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = combiner(res, t[l++]);
		if (r & 1) res = combiner(res, t[--r]);
	}
	return res;
}
//template end

int w[MAXN];
ll tree[MAXN * 2];
int ptr[MAXN];

ll combiner(ll a, ll b) {
	return max(a, b);
}

bool pred(int a, int b) {
	return w[a] < w[b];
}

int main() {
	scan(n);
	for (int i = 0; i < n; i++) {
		scan(w[i]);
		ptr[i] = i;
	}

	sort(ptr, ptr + n, pred);
	int idx2 = -1;
	unordered_map<int, int> cust;
	for (int i = 0; i < n; i++) {
		int idx = ptr[i];
		int j = w[idx];
		if (cust.find(j) == cust.end())
			idx2++;
		cust[j] = idx2;
	}

	for (int i = 0; i < n; i++) {
		int tmp = cust[w[i]];
		int v; scan(v);
		modify(tmp,
			query(tmp + 1, n, tree, combiner) + v,
			tree, combiner);
	}

	printf("%lld\n", query(0, n, tree, combiner));
}