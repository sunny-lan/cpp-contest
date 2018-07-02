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

int good[MAXN];
int bad[MAXN];

int main() {
	int n, m; scan(n); scan(m);
	int ig = 0, ib = 0;
	for (int i = 0; i < n; i++) {
		int s, p; scan(s); scan(p);
		if (p == 2) good[ig++] = s;
		else bad[ib++] = s;
	}

	sort(good, good + ig);
	sort(bad, bad + ib);

	int jg = 0, jb = 0;
	int tot = 0;
	int prot = 0;
	while (true) {
		int g = INT_MAX;
		int b = INT_MAX;
		if (jg < ig)g = good[jg];
		if (jb + 1 < ib)b = bad[jb] + bad[jb + 1];

		if (g == INT_MAX && b == INT_MAX)break;

		int alt = min(g, b);

		if (tot + alt > m)break;

		if (g <= b)jg++;
		else jb += 2;

		prot += 2, tot += alt;
	}

	while (jb < ib) {
		int alt = bad[jb++];
		if (tot + alt > m)break;
		prot++, tot += alt;
	}

	printf("%d\n", prot);
}