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

//template parameters
#define MAXN 8193
#define NUM int
int n;
//template begin
NUM bit[MAXN][MAXN];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p1, int p2, NUM v) {
	p1++, p2++;
	for (int x = p1; x < n; x += x&-x)
		for (int y = p2; y < n; y += y&-y)
			bit[x][y] += v;
}

NUM query(int p1, int p2) {
	p1++, p2++;
	NUM res = 0;
	for (int x = p1; x > 0; x -= x&-x)
		for (int y = p2; y > 0; y -= y&-y)
			res += bit[x][y];
	return res;
}

int h[MAXN];

int qrng(int a1, int a2, int b1, int b2) {
	return query(a1, a2)
		- query(a1, b2)
		- query(b1, a2)
		+ query(b1, b2);
}


int main() {
	scan(n);
	for (int i = 0; i < n; i++) {
		scan(h[i]);
		update(i, h[i], 1);
	}
	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int op; scan(op);
		if (op == 1) {
			int i, j, a, b; scan(i); scan(j); scan(a); scan(b);
			printf("%d\n", qrng(i-1, a-1, j, b));
		}
		else {
			int i, hn; scan(i); scan(hn);
			update(i, h[i], -1);
			update(i, h[i] = hn, 1);
		}
	}
}