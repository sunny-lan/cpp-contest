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

#define MAXN 2010
#define MAXB 11

bool pred(ll a, ll b) {
	return a > b;
}

ll sparse[MAXN][MAXB][MAXN];

inline int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

inline ll query(int t, int i, int j) {
	int bsI = count_bits(j - i);
	ll a = sparse[t][bsI][i],
		b = sparse[t][bsI][j - (1 << bsI)];
	return pred(a, b) ? a : b;
}

inline void construct(int t, int n) {
	int bs = 1, bsI = 0;
	bs <<= 1, bsI++;
	while (bs <= n) {
		for (int i = 0; i + bs <= n; i++) {
			ll a = sparse[t][bsI - 1][i], b = sparse[t][bsI - 1][i + (bs >> 1)];
			sparse[t][bsI][i] = pred(a, b) ? a : b;
		}
		bs <<= 1, bsI++;
	}
}

ll X, k;
int n, q;
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];
int ptr[MAXN];
int pred1(int x, int y) {
	return a[x] > a[y];
}

vector<double> paths[MAXN];

double findInter(int x, int y) {
	if (a[x] + b[y] == a[y] + b[x])return -1;
	return (X*(a[x] - a[y])) / (double)(a[x] - a[y] - b[x] + b[y]);
}

int main() {
	memset(sparse, 0x3f, sizeof sparse);
	scan(X); scan(k); scan(n); scan(q);
	for (int i = 0; i < n; i++) {
		scan(a[i]); scan(b[i]); scan(c[i]);
		ptr[i] = i;
	}	
	sort(ptr, ptr + n, pred1);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int idx = ptr[i];
		vector<pair<double, int>> inter;
		for (int j = 0; j < n; j++)if (j != idx) {
			double in = findInter(idx, j);
			if (in > 0 && in < X)
				inter.push_back({ in,j });
		}
		sort(inter.begin(), inter.end());
		ll sub = sum;
		int p = 0;
		double last = 0;
		for (auto cust : inter) {
			if (cust.first != last) {
				sparse[idx][0][p++] = sub;
				paths[idx].push_back(last);
				last = cust.first;
			}
			int line = cust.second;
			if (b[line] - a[line] > b[idx] - a[idx])
				sub += c[line];
			else
				sub -= c[line];
		}
		sparse[idx][0][p++] = sub;
		paths[idx].push_back(last);
		construct(idx, p);

		sum += c[idx];
	}

	for (int i = 0; i < q; i++) {
		int p; ll s; scan(p); scan(s);
		p--;
		int l = upper_bound(paths[p].begin(), paths[p].end(), (double)s) - paths[p].begin() - 1;
		l = max(l, 0);
		int r = lower_bound(paths[p].begin(), paths[p].end(), (double)s + k) - paths[p].begin();
		r = min((int)paths[p].size(), r);
		printf("%lld\n", query(p, l, r));
	}
}