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

#define MAXN 1000010
#define NUM pii

//template begin
NUM bit[MAXN];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y < MAXN; y += y&-y)
		bit[x] = max(bit[x], v);
}

NUM query(int p) {
	p++;
	NUM res = { 0,-1 };
	for (int x = p; x > 0; x -= x&-x)
		res = max(res, bit[x]);
	return res;
}

#define MAX2 100000
pii nums[MAX2];
int src[MAX2];
bool pred(const pii &a, const pii &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a > b;
}

int main() {
	memset(bit, -1, sizeof bit);
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		scan(nums[i].first);
		scan(nums[i].second);
	}

	sort(nums, nums + n, pred);

	for (int i = 0; i < n; i++) {
		pii res = query(nums[i].second);
		src[i] = res.second;
		update(nums[i].second, { res.first + 1 , i });
	}

	pii res = query(MAXN - 5);
	printf("%d\n", res.first);
	int tmp = res.second;
	while (tmp != -1) {
		printf("%d %d\n", nums[tmp].first, nums[tmp].second);
		tmp = src[tmp];
	}
	cin >> n;
}