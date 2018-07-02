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

#define MAXN 500000
#define MAXP 666
#define NUM int
//template begin
NUM bit[MAXP];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x <= MAXP; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int s1[MAXN];
int s2[MAXN];
int ptr[MAXN];
bool pred(int a, int b) {
	return s1[a] < s1[b];
}

int ans[MAXN];//num strictly less
int ans2[MAXN];//num strictly greater

int a0[MAXP];
int b0[MAXP];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; ++i) {
		scan(s1[i]); scan(s2[i]);
		ptr[i] = i;
		if (s1[i] == 0)
			a0[s2[i]]++;
		if (s2[i] == 0)
			b0[s1[i]]++;
	}
	sort(ptr, ptr + n, pred);
	int prev = -1;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		int idx = ptr[i];
		if (prev < s1[idx])
			while (!q.empty())
				update(q.front(), 1), q.pop();
		ans[idx] = n - query(s2[idx] - 1);
		if (s1[idx] == 650)
			ans[idx] -= a0[s2[idx]];
		if (s2[idx] == 650)ans[idx] -= b0[s1[idx]];
		q.push(s2[idx]);
		prev = s1[idx];
	}
	memset(bit, 0, sizeof bit);
	prev = INT_MAX;
	while (!q.empty())q.pop();
	for (int i = 0; i < n; i++) {
		int idx = ptr[n - i - 1];
		if (s1[idx] < prev)
			while (!q.empty())
				update(q.front(), 1), q.pop();
		ans2[idx] = i - query(s2[idx]) - q.size();
		q.push(s2[idx]);
		prev = s1[idx];
	}

	for (int i = 0; i < n; i++)
		printf("%d %d\n", ans2[i] + 1, ans[i]);
	cin >> n;
}