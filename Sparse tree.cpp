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
#include <stack>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000
#define MAXB 17

#define NUM int

bool pred(NUM a, NUM b) {
	return a < b;
}

NUM sparse[MAXB][MAXN * 2];

inline int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

//range is exclusive [i,j)
inline NUM query(int i, int j) {
	int bsI = count_bits(j - i);
	NUM a = sparse[bsI][i],
		b = sparse[bsI][j - (1 << bsI)];
	return pred(a,b) ? a : b;
}

inline void construct(int n) {
	int bs = 1, bsI = 0;
	bs <<= 1, bsI++;
	while (bs <= n) {
		for (int i = 0; i + bs <= n; i++) {
			NUM a = sparse[bsI - 1][i], b = sparse[bsI - 1][i + (bs >> 1)];
			sparse[bsI][i] = pred(a, b) ? a : b;
		}
		bs <<= 1, bsI++;
	}
}

NUM* val = sparse[0];

int main() {
	cout << "N:";
	int n; scan(n);
	for (int i = 0; i < n; i++)
		scan(val[i]);
	cout << "Q:";
	int q; scan(q);
	for (int i = 0; i, q; i++) {
		int l, r; scan(l); scan(r);
		cout << query(l, r) << endl;
	}
}