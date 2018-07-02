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

#define MAXN 10

int f[MAXN][3];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++)
		scanf("%d-%d-%d", &f[i][0], &f[i][1], &f[i][2]);
	int m; scan(m);
	int o = 0, v = 0, nc = 0,
		on = 0, ov = 0, nv = 0,
		ovn = 0;
	for (int i = 0; i < m; i++) {
		int oo = 0, vv = 0, nn = 0;
		char c;
		while (c = getchar())
			if (c == 'O') oo++;
			else if (c == 'V')vv++;
			else if (c == 'N')nn++;
			else break;
			if (oo > 0 && vv > 0 && nn > 0) ovn++;
			else if (oo > 0 && vv > 0) ov++;
			else if (oo > 0 && nn > 0) on++;
			else if (nn > 0 && vv > 0) nv++;
			else if (oo > 0)o++;
			else if (vv > 0)v++;
			else if (nn > 0)nc++;
	}
	for (int i = 0; i < n; i++) {
		int oo = f[i][0], vv = f[i][1], nn = f[i][2];
		oo -= o, vv -= v, nn -= nc;
		for (int a = 0; a <= on; a++)
			for (int b = 0; b <= ov; b++)
				for (int c = 0; c <= nv; c++)
				{
					int to = oo - a - (ov - b), 
						tv = vv - b - (nv - c), 
						tn = nn - c - (on - a);
					to = max(to, 0), tv = max(tv, 0), tn = max(tn, 0);
					if (to + tv + tn <= ovn)
					{
						printf("DA\n");
						goto outer;
					}
				}
		printf("NE\n");
	outer:continue;
	}
	cin >> n;
}