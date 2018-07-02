#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

struct vec2 {
	double x, y;

	vec2(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

struct line {
	vec2 p, q;
	line(vec2 _p=vec2(), vec2 _q=vec2()) {
		p = _p, q = _q;
	}
};

bool inter(line w, line s) {
	double wa = w.q.y - w.p.y,
		wb = w.p.x - w.q.x,
		wc = wa*w.p.x + wb*w.p.y,
		sa = s.q.y - s.p.y,
		sb = s.p.x - s.q.x,
		sc = sa*s.p.x + sb*s.p.y;
	double det = wa*sb - sa*wb;
	if (det == 0)return false;
	double xint = (sb*wc - wb*sc) / det,
		yint = (wa*sc - sa*wc) / det;
	double wlx = min(w.p.x, w.q.x), wrx = max(w.p.x, w.q.x),
		wly = min(w.p.y, w.q.y), wry = max(w.p.y, w.q.y),
		slx = min(s.p.x, s.q.x), srx = max(s.p.x, s.q.x),
		sly = min(s.p.y, s.q.y), sry = max(s.p.y, s.q.y);
	if (xint >= wlx && xint <= wrx && yint >= wly && yint <= wry)
		if (xint >= slx && xint <= srx && yint >= sly && yint <= sry)return true;
	return false;
}

int main() {
	line w;
	scanf("%lf %lf %lf %lf", &w.p.x, &w.p.y, &w.q.x, &w.q.y);
	int n; scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		vec2 fst, lst; bool flg=false;
		bool dfbg = false;
		for (int j = 0; j < c; j++) {
			vec2 pt; scanf("%lf %lf", &pt.x, &pt.y);
			if (!flg)
				fst = pt, flg = true;
			else
				dfbg |= inter(w, line(lst, pt));
			lst = pt;
		}
		dfbg |= inter(w, line(lst, fst));
		if (dfbg)res++;
	}
	printf("%d", res);
	cin >> n;
}