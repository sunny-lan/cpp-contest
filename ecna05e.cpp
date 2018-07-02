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

#define MAXN 15
#define MAXM 20

int p[MAXN];
int sz[MAXN];
void con(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}
int f(int x) {
	if (p[x] == x)return x;
	return p[x] = f(p[x]);
}
void me(int x, int y) {
	int px = f(x),
		py = f(y);
	if (px == py)return;
	sz[px] += sz[py];
	sz[py] = 0;
	p[py] = px;
}

int popcnt(int i)
{
	// Java: use >>> instead of >>
	// C or C++: use uint32_t
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

pair<pii, int> e[MAXM];

bool connected[1 << MAXM];

int main() {
	for (int t = 1;; t++) {
		memset(connected, false, sizeof connected);
		int n, m; scan(n); scan(m);
		if ((n | m) == 0)break;
		for (int i = 0; i < m; i++)
		{
			int a, b, c; scan(a); scan(b); scan(c);
			e[i] = { {--a,--b},c };
		}

		for (int i = 0; i < (1 << m); i++) {
			con(n);
			for (int j = 0; j < m; j++)if ((i >> j) & 1)
				me(e[j].first.first, e[j].first.second);
			connected[i] = sz[f(0)] == n;
		}
		int mini = INT_MAX;
		for (int i = 1; i < (1 << m); i++) {
			if (popcnt(i) < n - 1)continue;
			int cnt = 0;
			for (int cut = 0; cut < m; cut++) if ((i >> cut) & 1) {
				cnt += e[cut].second;
				if (!connected[i&~(1 << cut)])goto nxt;
			}
			mini = min(mini, cnt);
		nxt:continue;
		}
		if (mini == INT_MAX)
			printf("There is no reliable net possible for test case %d.\n", t);
		else
			printf("The minimal cost for test case %d is %d.\n", t, mini);
	}
}