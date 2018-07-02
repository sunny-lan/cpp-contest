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

int loc[MAXN];
int vis[MAXN];

int main() {
	int s, k; scan(s); scan(k);
	for (int i = 0; i < s; i++) {
		int x; scan(x);
		loc[--x] = i;
	}

	ll tot = 1;
	int curr; scan(curr);
	curr--;
	for (int i = 0; i < k - 1; i++) {
		int nxt; scan(nxt);
		tot += abs(loc[curr] - loc[--nxt]);
		curr = nxt;
	}

	printf("%lld\n", tot);
	cin >> s;
}