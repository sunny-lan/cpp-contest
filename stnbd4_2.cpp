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

#define MAXN 100000

#define NUM ll
int n;

//template begin
NUM bit[MAXN];
//NOTE: p is inclusive [0,p]

void update(int p, NUM v) {
	if (p == 0)return;
	for (int x = p; x <= n; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

NUM query(int l, int r) {
	return query(r - 1) - query(l - 1);
}


ll a[MAXN];
int aS[MAXN];

int pred(int x, int y) {
	return a[x] < a[y];
}

int bs;

bool pred2(pair<pii, int> x, pair<pii, int> y) {
	pii ax = x.first,
		ay = y.first;
	int bx = ax.first / bs,
		by = ay.first / bs;
	if (bx == by)
		return ax.second < ay.second;
	return bx < by;
}

pair<pii, int> q[MAXN];
unordered_map<ll, int> ord;

ll ans[MAXN];
int ptr[MAXN];

int main() {
	int N; scan(N);
	bs = sqrt(N);
	for (int i = 0; i < N; i++) {
		scan(a[i]);
		aS[i] = i;
	}

	sort(aS, aS + N, pred);

	int idx = 1;
	for (int i = 0; i < N; i++) {
		if (ord[a[aS[i]]] == 0) {
			ord[a[aS[i]]] = idx;
			idx++;
		}
		ptr[aS[i]] = ord[a[aS[i]]];
	}
	n = idx;

	int Q; scan(Q);
	for (int i = 0; i < Q; i++) {
		int l, r; scan(l); scan(r);
		q[i] = { { --l, r } ,i };
	}

	sort(q, q + Q, pred2);

	int cl = 0, cr = 0;
	ll cnt = 0;
	for (int i = 0; i < Q;i++) {
		auto qu = q[i];
		int l = qu.first.first,
			r = qu.first.second;

		//remove elems from left side
		while (cl < l) {
			int v = ptr[cl];
			update(v, -1);
			cnt -= query(1, v);
			cl++;
		}

		//add elems to left side
		while (cl > l) {
			cl--;
			int v = ptr[cl];
			update(v, 1);
			cnt += query(1, v);
		}

		//add elems to right side
		while (cr < r) {
			int v = ptr[cr];
			update(v, 1);
			cnt += query(v + 1, n);
			cr++;
		}

		//remove elems from right side
		while (cr > r) {
			cr--;
			int v = ptr[cr];
			update(v, -1);
			cnt -= query(v + 1, n);
		}

		ans[qu.second] = cnt;
	}

	for (int i = 0; i < Q; i++)
		printf("%lld\n", ans[i]);

	cin >> N;
}