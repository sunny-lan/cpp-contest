#include <bits/stdc++.h>
using namespace std;

struct vec {
	int x, y;
};

struct rect {
	vec p, q;
};

#define MAXN 100

rect rs[MAXN];

bool between(int a, int b, int x, bool inc = false) {
	if(inc)
		return x >= min(a, b) && x <= max(a, b);
	return x > min(a, b) && x < max(a, b);
}

bool ptin(rect a, vec pt, bool inc = false) {
	return between (a.p.x, a.q.x, pt.x, inc) && between (a.p.y, a.q.y, pt.y, inc);
}

bool rinter(rect a, rect b, bool inc = false) {
	return ptin(a, b.p, inc) || ptin(a, b.q, inc) || ptin(a, {b.p.x, b.q.y}, inc) || ptin(a, {b.q.x, b.p.y}, inc);
}

bool rin(rect a, rect b, bool inc = true) {
	return ptin(a, b.p, inc) && ptin(a, b.q, inc) && ptin(a, {b.p.x, b.q.y}, inc) && ptin(a, {b.q.x, b.p.y}, inc);
}

rect mrgrect(rect a, rect b) {
	return {
		{	min(min(a.p.x, a.q.x), min(b.p.x, b.q.x)),
			min(min(a.p.y, a.q.y), min(b.p.y, b.q.y))
		},
		{	max(max(a.p.x, a.q.x), max(b.p.x, b.q.x)),
			max(max(a.p.y, a.q.y), max(b.p.y, b.q.y))
		}
	};
}

int peri(rect a) {
	int w = abs(a.p.x - a.q.x), h = abs(a.p.y - a.q.y);
	return w * 2 + h * 2;
}

int p[MAXN];
int f(int x) {
	if(p[x] == x)
		return x;
	return p[x] = f(p[x]);
}

bool kusted[MAXN];
vector<rect> md;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", rs[i].p.x, rs[i].p.y, rs[i].q.x, rs[i].q.y);
		for(int j = 0; j < i; j++)
			if(rinter(rs[0], rs[j]))
			rs[0]=mrgrect(rs[0], rs[j]), kusted[j]=true;
	}
	for(int i = 0; i < n; i++) {
		int pi = f(i);
		cmps[pi] = mrgrect(cmps[pi], rs[i]);
		did[pi] = true;
	}
	int tot = peri(rs[0]);


    printf("%d\n", tot);
}
