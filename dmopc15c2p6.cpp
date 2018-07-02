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

#define MAXM 10
#define MAXN 100000

int xm[MAXM];
int ym[MAXM];

struct evt {
	int x, y1, y2;
	bool s;
	evt(int _x, int _y1, int _y2, bool _s) {
		x = _x, y1 = _y1, y2 = _y2, s = _s;
	}
};
bool pred(const evt &a, const evt &b) {
	if (a.x == b.x)
		return a.y1 < b.y1;
	return a.x < b.x;
}

inline void rotate(int &x, int &y) {
	int tx = x, ty = y;
	x = tx + ty;
	y = ty - tx + 4001;
}

vector<evt> e;

int _g[100000];
int *g = _g + 50000;

int main() {
	int m; scan(m);
	for (int i = 0; i < m; i++) {
		scan(xm[i]); scan(ym[i]);
	}

	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int x, y; scan(x); scan(y);
		int d = INT_MAX;
		for (int j = 0; j < m; j++)
			d = min(d, abs(x - xm[j]) + abs(y - ym[j]));
		d = max(d - 1, 0);
		rotate(x, y);
		int l = min(y + d, y - d), a = max(y + d, y - d),
			w = min(x - d, x + d), q = max(x - d, x + d);
		e.push_back(evt(w, l, a + 1, true));
		e.push_back(evt(q + 1, l, a + 1, false));
	}
	sort(e.begin(), e.end(), pred);

	int a = 0;
	int idx = 0;
	for (int j = -8000; j <= 8000; j++) {
		while (idx < e.size() && e[idx].x == j)
			if (e[idx].s)
				g[e[idx].y1]++, g[e[idx].y2]--, idx++;
			else
				g[e[idx].y1]--, g[e[idx].y2]++, idx++;
		int s = 0;
		for (int i = -8000; i <= 8000; i++)
			s += g[i], a = max(a, s);
	}

	printf("%d\n", a);
}