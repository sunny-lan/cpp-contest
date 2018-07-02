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
#include <list>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 500010
#define THETA 1000000.0
#define NUM pii

NUM bit[MAXN];

void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x & -x)
		bit[x] = max(bit[x], v);
}

NUM query(int p) {
	p++;
	NUM res = { 0, -1 };
	for (int x = p; x > 0; x -= x & -x)
		res = max(res, bit[x]);
	return res;
}

list<int>::iterator it[MAXN];
int ptr[MAXN];
bool lis[MAXN];

int main() {
	memset(bit, -1, sizeof bit);

	int n, m;
	scan(n);
	scan(m);

	list<int> nums;
	for (int i = 0; i < n; i++) {
		it[i] = nums.insert(nums.end(), i);
	}

	for (int i = 0; i < m; i++) {
		char op;
		int x, y;
		scanf(" %c %d %d", &op, &x, &y);
		x--, y--;
		if (op == 'A') {
			nums.erase(it[x]);
			it[x] = nums.insert(it[y], x);
		}
		else {
			nums.erase(it[x]);
			it[x] = nums.insert(next(it[y]), x);
		}
	}

	for (int idx : nums) {
		//printf("%d ", idx);
		pii res = query(idx);
		ptr[idx] = res.second;
		update(idx, { res.first + 1, idx });
	}
	//printf("\n");

	int curr = query(n - 1).second;
	int last = curr;
	while (curr != -1) {
		lis[curr] = true;
		curr = ptr[curr];
	}

	vector<pair<char, pii>> ops;

	for (int i = 0; i < n; i++)
		if (lis[i])
			for (int j = i - 1; j >= 0 && !lis[j]; j--)
				ops.push_back({ 'A',{ j, j + 1 } });

	for (int i = last + 1; i < n; i++)
		ops.push_back({ 'B',{ i, i - 1 } });

	printf("%d\n", (int)ops.size());
	for (auto op : ops)
		printf("%c %d %d\n", op.first, op.second.first + 1, op.second.second + 1);

	cin >> n;
}