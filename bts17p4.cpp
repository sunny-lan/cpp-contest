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
using namespace std;

#define memeset memset

template<typename T>
inline T INF(T a) { return a == -1 ? INT_MAX : a; }
inline int _INF(int a) { return a == INT_MAX ? -1 : a; }

template<typename T>
inline T INF_MAX(T a, T b) { return INF(a) > INF(b) ? a : b; }

template<typename T>
inline T INF_MIN(T a, T b) { return INF(a) < INF(b) ? a : b; }


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100003

//template begin
//NOTE: indices are indexed at 0, in the form [l, r)
int n;  // array size

template <typename NUM>
void build(NUM *t, NUM(*combiner)(NUM, NUM)) {  // build the tree
	for (int i = MAXN - 1; i > 0; --i) t[i] = combiner(t[i << 1], t[i << 1 | 1]);
}

template <typename NUM>
void modify(int p, NUM value, NUM *t, NUM(*combiner)(NUM, NUM)) {  // set value at position p
	for (t[p += MAXN] = value; p > 1; p >>= 1) t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

template <typename NUM>
NUM query(int l, int r, NUM *t, NUM(*combiner)(NUM, NUM)) {  // sum on interval [l, r)
	NUM res;
	bool flag = false; //prevents needing identity
	for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
		if (l & 1) (res = flag ? combiner(res, t[l++]) : t[l++]), flag = true;
		if (r & 1) (res = flag ? combiner(res, t[--r]) : t[--r]), flag = true;
	}
	return res;
}
//template end

int _min(int a, int b) {
	return min(a, b);
}


int tree[2 * MAXN];


int muds[MAXN];

int dp[MAXN];

int main() {
	memset(muds, -1, sizeof muds);

	int m, j; scan(n); scan(m); scan(j);

	for (int i = 1; i <= m; i++) {
		int p, t; scan(p); scan(t);
		muds[p] = t;
	}
	muds[n + 1] = 0;
	for (int i = 1; i < MAXN; i++) {
		dp[i] = INT_MAX;
	}

	int res;
	if (n <= 1000) {
		for (int i = 1; i <= n + 1; i++) {
			if (muds[i] == -1)continue;
			int mini = INT_MAX;
			for (int k = max(0, i - j); k < i; k++) {
				mini = min(dp[k], mini);
			}
			dp[i] = max(muds[i], mini);
		}
		res = dp[n + 1];
	}
	else {

		for (int i = 0; i <= n; i++) {
			tree[i + MAXN] = INT_MAX;
		}
		build(tree, _min);

		modify(0, 0, tree, _min);

		for (int i = 1; i <= n + 1; i++)if (muds[i] != -1) {
			int v = query(max(0, i - j), i, tree, _min);
			modify(i, max(muds[i], v), tree, _min);
		}

		 res = query(n + 1, n + 2, tree, _min);
		
	}if (res == INT_MAX)res = -1;
	cout << res << endl;
	cin >> n;
}