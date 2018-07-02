#ifdef DMOJ

#include <bits/stdc++.h>

#define gc getchar_unlocked

void scan(long long &x)
{
	register long long c = gc();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

void scan(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

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
#include <stack>
#include <set>

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 100010
#define MAXB 20

int h[MAXN];

int sparse[MAXB][MAXN * 2];

inline int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

inline int query(int i, int j) {
	int bsI = count_bits(j - i);
	int a = sparse[bsI][i],
		b = sparse[bsI][j - (1 << bsI)];
	return h[a] < h[b] ? a : b;
}

inline void construct(const vector<int> &val) {
	int bs = 1, bsI = 0, n = val.size();
	for (int i = 0; i < n; i++)sparse[bsI][i] = val[i];
	bs <<= 1, bsI++;
	while (bs < n) {
		for (int i = 0; i + bs <= n; i++)
			sparse[bsI][i] = min(sparse[bsI - 1][i], sparse[bsI - 1][i + (bs >> 1)]);
		bs <<= 1, bsI++;
	}
}

vector<int> children[MAXN];

//euclidean tour stuff
vector<int> tour;
vector<int> locs[MAXN];

void dfs(int i) {
	locs[i].push_back(tour.size()), tour.push_back(i);
	for (int child : children[i]) {
		h[child] = h[i] + 1;
		dfs(child);
		locs[i].push_back(tour.size()), tour.push_back(i);
	}
}

unordered_map<int, vector<int>::iterator> cache[MAXN];

vector<int>::iterator qe(int i, int k) {
	auto f = cache[i].find(k);
	if (f != cache[i].end())return cache[i][k];
	return cache[i][k] = upper_bound(locs[i].begin(), locs[i].end(), k);
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int c; scan(c);
		for (int j = 0; j < c; j++) {
			int child; scan(child);
			children[i].push_back(--child);
		}
	}
	dfs(0);
	construct(tour);
	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int src, dst; scan(src); scan(dst);
		if (src == dst) {
			printf("0\n");
			continue;
		}
		src--, dst--;
		int lsrc = locs[src][0], ldst = locs[dst][0];
		int lca = query(min(lsrc, ldst), max(lsrc, ldst) + 1);
		int adstL = locs[lca][0],adstR = ldst;
		ll tot = adstR - adstL;
		if (lsrc > ldst) {
			auto asrcR = qe(lca, lsrc),asrcL = lca == src ? asrcR : asrcR - 1;
			tot += *asrcR - *asrcL;
		}
		tot -= h[src] - h[lca];
		printf("%lld\n", tot);
	}
}