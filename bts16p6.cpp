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
using namespace std;

#define memeset memset
#define INF(a) (a==-1?INT_MAX:a)
#define MAX(a, b) (a>b?a:b)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 500

ll pre[MAXN + 1][MAXN + 1];

int r, c;

void build() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			pre[i][j + 1] += pre[i][j];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			pre[j + 1][i] += pre[j][i];
}

int main() {
	int  m; scan(c); scan(r); scan(m);
	for (int i = 0; i < m; i++) {
		int c1, r1, w, h, n;
		scan(c1); scan(r1); scan(w); scan(h); scan(n);
		c1--, r1--;
		pre[r1][c1] += n;
		pre[r1][c1 + w] -= n;
		pre[r1 + h][c1] -= n;
		pre[r1 + h][c1 + h] += n;
	}

	build(); build();

	queue<pair<pair<pii, pair<int, ll>>, ll>> q;
	int c1, r1; scan(c1); scan(r1);
	q.push({ { {r1,c1},{0,pre[r1][c1]} },-1 });
	pair<int, ll> best = {-1,-1};
	while (!q.empty()) {
		auto curr1 = q.front(); q.pop();
		ll last = curr1.second;
		auto curr = curr1.first;
		int r2 = curr.first.first, c2 = curr.first.second;
		if (r2 < 0 || c2 < 0 || r2 >= r || c2 >= c) continue;
		if (pre[r2][c2] <= last)continue;
		pair<int, ll> newCost = { curr.second.first + 1, curr.second.second + pre[r2][c2] };
		best = MAX(best, newCost);
		q.push({ { {r2 + 1, c2}, newCost },pre[r2][c2] });
		q.push({ { { r2 + 1, c2 }, newCost },pre[r2][c2] });
		q.push({ { { r2 + 1, c2 }, newCost },pre[r2][c2] });
		q.push({ { { r2 + 1, c2 }, newCost },pre[r2][c2] });
	}
	cout << best.second << endl;
	cin >> m;
}