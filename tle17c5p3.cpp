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

#define MAXN 201
#define U 0
#define I 1
#define P 2

bool type[3][MAXN];
bool mults[MAXN];

int main() {
	memset(type[I], true, sizeof type[I]);
	int n; scan(n);
	printf("Units:\n");
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++)
		{
			if (u*v%n == 1) {
				type[U][u] = true;
				printf("%d\n", u);
				break;
			}
		}
	}
	for (int u = 0; u < n; u++)
		if(!type[U][u])
		for (int v = 0; v<n; v++)
			if (!type[U][v])
				type[I][u*v%n] = false;
	printf("Irreducibles:\n");
	for (int u = 1; u < n; u++)
		if (!type[U][u])
			if (type[I][u])
				printf("%d\n", u);
	printf("Primes:\n");
	for (int p = 1; p < n; p++)if(!type[U][p]) {
		memset(mults, false, sizeof mults);
		
		for (int y = 0; y < n; y++)
			mults[y*p%n] = true;
		
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)
				if (mults[a*b%n])
					if (!(mults[a] || mults[b]))
						goto outer;
		printf("%d\n", p);
	outer:continue;
	}
	cin >> n;
}