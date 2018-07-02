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


int popcnt(int i)
{
	// Java: use >>> instead of >>
	// C or C++: use uint32_t
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}


int adj[22];
int tadj[22];

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++)
		adj[i] |= 1 << i;
	for (int i = 0; i < m; i++) {
		int u, v; scan(u); scan(v);
		u--, v--;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;
	}
	int cheese = (1 << n) - 1;
	for (int i = 0; i < 1 << n; i++) {
		memcpy(tadj, adj, sizeof tadj);
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1)
				tadj[j] |= i;
			if (tadj[j] != cheese)goto nxt;
		}
		printf("%d\n", popcnt(i));
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1)
				printf("%d ", j + 1);
		printf("\n");
		break;
	nxt:continue;
	}
	cin >> cheese;
}