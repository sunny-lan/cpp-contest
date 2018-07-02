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
#define scan(y) do{while((y=getchar())<'0'); for(y-='0'; '0'<=(_=getchar()); y=(y<<3)+(y<<1)+_-'0');}while(0)
char _;

struct rect {
	int x1, x2, y1, y2;
	rect() {
		x1 = x2 = y1 = y2 = -INT_MAX;
	}
	rect(int _x1, int _y1, int _x2, int _y2) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

struct lineinf {
	int x;
	int y1, y2;
	bool first;

	lineinf() {
		x = y1 = y2 = -INT_MAX;
		first = true;
	}

	lineinf(int _x, bool _first, int _y1, int _y2) {
		first = _first;
		x = _x;
		y1 = _y1;
		y2 = _y2;
	}
};

bool pred1(lineinf a, lineinf b) {
	return a.x < b.x;
}

int _covered[20010];
int* covered = _covered + 10005;

rect rects[5000];
lineinf lines[10000];
int n;

ll ls() {
	memset(_covered, 0, sizeof _covered);
	memset(lines, 0, sizeof lines);

	for (int i = 0; i < n; i++) {
		rect r = rects[i];
		int start = min(r.y1, r.y2);
		int stop = max(r.y1, r.y2);
		lines[i * 2] = lineinf(min(r.x1, r.x2), true, start, stop);
		lines[i * 2 + 1] = lineinf(max(r.x1, r.x2), false, start, stop);
	}
	sort(lines, lines + n * 2, pred1);

	ll tot = 0;
	for (int i = 0; i<n * 2; i++) {
		lineinf l = lines[i];
		if (!l.first) covered[l.y1]--, covered[l.y2]++;
		ll sum = 0;
		for (int y = -10000; y <= 10000; y++) {
			sum += covered[y];
			if (sum == 0 && y >= l.y1 && y < l.y2)
				tot++;
		}
		if (l.first)covered[l.y1]++, covered[l.y2]--;
	}
	return tot;
}

int main() {
	memset(rects, 0, sizeof rects);
	scan(n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		rect tmp(a, b, c, d);
		rects[i] = tmp;
	}
	ll tot = ls();
	for (int i = 0; i < n; i++) {
		rect r = rects[i];
		rect tmp(r.y1, r.x1, r.y2, r.x2); rects[i] = tmp;
	}
	tot += ls(); 
	printf("%lld\n", tot);
	cin >> n;
}