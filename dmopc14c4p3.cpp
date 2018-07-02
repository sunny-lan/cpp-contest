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
#include <functional>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000

int du[MAXN][MAXN];
bool inq[MAXN][MAXN];

int cost[MAXN][MAXN];

int main() {
	memset(du, 0x3f, sizeof du);

	int l, d; scan(l); scan(d);
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < l; j++) {
			scan(cost[i][j]);
		}
	}

	int dl, dd; scan(dl); scan(dd);

	du[0][0] = cost[0][0];
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	q.push({ cost[0][0], {0,0} });
	while (!q.empty()) {
		auto curr = q.top(); q.pop();
		pii loc = curr.second;
		inq[loc.first][loc.second] = false;
		int ni = loc.first + 1, nj = loc.second;
		if (ni < d && nj >= 0 && nj < l) {
			int alt = du[loc.first][loc.second] + cost[ni][nj];
			if (alt < du[ni][nj]) {
				du[ni][nj] = alt;
				if (!inq[ni][nj])
				{
					q.push({ alt,{ni,nj} });
					inq[ni][nj] = true;
				}
			}
		}

		ni = loc.first, nj = loc.second + 1;
		if (ni < d && nj >= 0 && nj < l) {
			int alt = du[loc.first][loc.second] + cost[ni][nj];
			if (alt < du[ni][nj]) {
				du[ni][nj] = alt;
				if (!inq[ni][nj])
				{
					q.push({ alt,{ ni,nj } });
					inq[ni][nj] = true;
				}
			}
		}

		ni = loc.first, nj = loc.second - 1;
		if (ni < d && nj >= 0 && nj < l) {
			int alt = du[loc.first][loc.second] + cost[ni][nj];
			if (alt < du[ni][nj]) {
				du[ni][nj] = alt;
				if (!inq[ni][nj])
				{
					q.push({ alt,{ ni,nj } });
					inq[ni][nj] = true;
				}
			}
		}
	}

	printf("%d\n", du[dd][dl]);
}