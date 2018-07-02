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

#define MAXX 1000000
#define MAXH 1000
int p[MAXH];
int v[MAXH];
int h, k;

bool f(int l) {
	memset(v, false, sizeof v);
	int cnt = 0;
	int covered = -1;
	for (int i = 0; i < h; i++)
		if (p[i] > covered)
			cnt++,
			v[i] = true,
			covered = p[i] + 2 * l;

	covered -= MAXX;
	if (covered >= 0)
		for (int i = 0; i < h; i++)
			if (p[i] > covered)break;
			else
				if (v[i])cnt--;

	return cnt <= k;
}

int main() {
	scan(h);
	for (int i = 0; i < h; i++)
		scan(p[i]);
	sort(p, p + h);
	scan(k);
	int lo = 0,
		hi = MAXX;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("%d\n", lo);
	cin >> h;
}