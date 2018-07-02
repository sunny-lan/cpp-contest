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

#define MAXN 6
#define MAXP 11100

#define NUM ll

int n=4;
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

ll value[MAXP];

int main() {
	
	base[0] = 1;
	for (int i = 0; i < n; i++) {
		scan(l[i]);
		base[i + 1] = base[i] * l[i];
	}

	for (int x = 1; x <= l[0] ; x++) {
		for (int y = 1; y <= l[1] ; y++) {
			for (int z = 1; z <= l[2] ; z++) {
				for (int w = 1; w <= l[3] ; w++) {
					int idx = 0;
					p[0] = x, p[1] = y, p[2] = z, p[3] = w;
					for (int j = 0; j < n; j++) {
						idx += (p[j] - 1) * base[j];
					}
					scanf("%lld",&v);
					update(0, 0);
				}
			}
		}
	}

	ll maxi = -(1ll << 55);
	for (int x = 1; x <= l[0]; x++) {
		for (int y = 1; y <= l[1]; y++) {
			for (int z = 1; z <= l[2]; z++) {
				for (int w = 1; w <= l[3]; w++) {
					for (int a = x ; a <= l[0]; a++) {
						for (int q = y ; q <= l[1]; q++) {
							for (int c = z ; c <= l[2]; c++) {
								for (int d = w ; d <= l[3]; d++) {
									ll res = 0;
									for (int i = 0; i < 1 << n; i++) {
										p[0] = x - 1, p[1] = y - 1, p[2] = z - 1, p[3] = w - 1;
										b[0] = a, b[1] = q, b[2] = c, b[3] = d;
										int mult = 1;
										int bcnt = 0;
										for (int j = 0; j < n; j++)
											if ((i>> j) & 1)
												p[j] = b[j], bcnt++;

										if (bcnt % 2 == (n + 1) % 2)
											mult = -1;
										res += query(0, 0)*mult;
									}

									maxi = max(maxi, res);
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%lld\n", maxi);

	cin >> maxi;
}