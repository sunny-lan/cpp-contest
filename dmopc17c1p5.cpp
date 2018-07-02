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
#include <stack>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000000

#define NUM int

//template begin
NUM bit[MAXN];

void update(int p, NUM v) {
	for (int x = p; x <= MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

pair<pii, int> queries[MAXN];

pii nums[MAXN];

int ans[MAXN];

int main() {
	int n, q; scan(n); scan(q);

	stack<pii> s;
	s.push({ -1, INT_MAX });
	for (int i = 0; i < n; i++)
	{
		int curr; scan(curr);
		curr--;
		while (s.top().second < curr)
			s.pop();
		nums[i] = { s.top().first, i };
		s.push({ i, curr });
	}

	sort(nums, nums + n);

	for (int i = 0; i < q; i++)
	{
		int l, r; scan(l); scan(r);
		queries[i] = { {l - 1,r},i };
	}

	sort(queries, queries + q);

	int nIdx = 0;
	int qIdx = 0;

	for (int i = 0; i < n; i++) {
		while (nIdx < n && nums[nIdx].first < i) {
			update(nums[nIdx].second + 1, 1);
			nIdx++;
		}

		while (qIdx < q && queries[qIdx].first.first == i)
		{
			ans[queries[qIdx].second] = query(queries[qIdx].first.second) - query(queries[qIdx].first.first);
			qIdx++;
		}
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}