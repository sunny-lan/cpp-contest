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
#include <cstddef>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//GUD CONTENT:
//sum for rectangle prism in any dimension
//let (a1,a2,...,an) be the first point
//let (b1,b2,...,bn) be the second point (should have larger coordinates)
//answer should be sum of psa(...) for all combinations of a and b for each dimension
//each term of sum can either have positive sign or negative sign.
//if it has odd number of dimesions in b, sign is negative
//if it has even number, sign is positive

#define MAXN 12
#define MAXP 11000000

#define NUM int

int n;
int l[MAXN];
int base[MAXN];

int p[MAXN];
NUM v;

NUM bit[MAXP];
inline void update(int di, int pt) {
	if (di == n)
		bit[pt] += v;
	else
		for (int x = p[di]; x <= l[di]; x += x&-x)
			update(di + 1, pt + base[di] * (x - 1));
}

inline NUM query(int di, int pt) {
	if (di == n)
		return bit[pt];
	else {
		NUM res = 0;
		for (int x = p[di]; x > 0; x -= x&-x)
			res += query(di + 1, pt + base[di] * (x - 1));
		return res;
	}
}

int b[MAXN];

short value[MAXP];

int main() {
	int q; scan(n); scan(q);
	base[0] = 1;
	for (int i = 0; i < n; i++) {
		scan(l[i]);
		base[i + 1] = base[i] * l[i];
	}

	for (int i = 0; i < q; i++) {
		int op; scan(op);
		int idx = 0;
		for (int j = 0; j < n; j++) {
			scan(p[j]);
			idx += (p[j] - 1) * base[j];
		}
		if (op == 1) {
			scan(v);
			int tmp = v;
			v -= value[idx];
			value[idx] = tmp;
			update(0, 0);
		}
		else {
			for (int j = 0; j < n; j++) {
				scan(b[j]);
				p[j]--;
			}
			int res = 0;
			for (int l = 0; l < 1 << n; l++) {
				int mult = 1;
				int bcnt = 0;
				for (int j = 0; j < n; j++)
					if ((l >> j) & 1)
						p[j] = b[j], bcnt++;
					
				if (bcnt % 2 == (n + 1) % 2)
					mult = -1;
				res += query(0, 0)*mult;
			}
			//if (res < 0)while (true)printf("e");
			printf("%lld\n", res);
		}
	}
	cin >> q;
}