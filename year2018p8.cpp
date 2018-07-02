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
#include <set>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll h[50][2000];
int direct[51][2001];

void dec(int i, int j) {
	direct[i][j] = max(0, direct[i][j] - 1);
}

int main() {
	int r, c, k, q; scan(r); scan(c); scan(k); scan(q);
	for (int i = 0; i <= r; i++)
		for (int j = 0; j <= c; j++)
			direct[i][j] = 2;
	for (int i = 0; i <= c; i++)
		direct[0][i] = 1;
	for (int i = 0; i <= r; i++)
		direct[i][0] = 1;
	for (int i = 0; i < q; i++) {
		int op, a, b, c1, d1; scan(op); scan(a); scan(b); scan(c1); scan(d1);
		a--, b--, c1--, d1--;
		if (op == 1) {
			ll v; scan(v);
			if (direct[a][b] != 0 && h[a][b] + v >= k) {
				int l = b;
				int lastc = -1;
				for (int cr = a; cr < r && l < c; cr++) {
					//process current range
					int nxtl = -1;
					int clastc;
					for (int cc = l; cc < c; cc++) {
						direct[cr][cc ] = 0;//kill this one
						clastc = cc;

						if (nxtl == -1 && direct[cr + 1][cc] == 1)
							//check if under can be nxtl
							nxtl = cc;
						else
							dec(cr+1, cc);

						//if other one stops progression or is already dead, break
 						if (nxtl == -1 || cc > lastc) { //only if out of shadow of prev
							if (direct[cr][cc + 1] == 0)break;
							if (direct[cr][cc + 1] == 2) { dec(cr, cc + 1); break; }
						}
					}
					if (nxtl == -1) {
						//for (int cc = l; cc <= lastc; cc++)
							//dec(cr + 1, cc);
						break;
					}
					l = nxtl;
					lastc = clastc;
				}

			}
			h[a][b] += v;
		}
		else {
			if (direct[0][0]==0 || direct[c1][d1] == 0)
				printf("no\n");
			else
				printf("yes\n");
		}
	}
	cin >> r;
}