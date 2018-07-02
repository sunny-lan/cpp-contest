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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int p[MAXN];
int res[MAXN];

int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++)
		p[i] = i;

	int cnt = 0;

	for (int i = 0; i < m; i++) {
		if (cnt >= n - 1 || (n-1)-cnt>m-i)break;
		int u, v; scan(u); scan(v);
		u--, v--;
		int pu = find(u),
			pv = find(v);
		if (pu == pv)continue;
		res[cnt++]=i;
		p[pu] = pv;
	}
	if (cnt != n - 1)
		printf("Disconnected Graph\n");
	else
		for (int i=0;i<n-1;i++)
			printf("%d\n", res[i] + 1);
}