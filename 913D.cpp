#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define MAXN 200010
#define NUM pli

NUM bit[MAXN];
void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		bit[x].first += v.first,
		bit[x].second += v.second;
}

NUM query(int p) {
	p++;
	NUM res = { 0, 0 };
	for (int x = p; x > 0; x -= x&-x)
		res.first += bit[x].first,
		res.second += bit[x].second;
	return res;
}

int a[MAXN]; ll t[MAXN];
int car1[MAXN], car2[MAXN];
bool pred1(int x, int y) {
	return a[x] > a[y];
}
bool pred2(int x, int y) {
	return t[x] < t[y];
}

int main() {
	int n; ll l; scan(n); scan(l);
	for (int i = 0; i < n; i++) {
		scan(a[i]); scan(t[i]);
		car1[i] = car2[i] = i;
	}
	sort(car1, car1 + n, pred1);
	sort(car2, car2 + n, pred2);
	unordered_map<int, int> ord;
	for (int i = 0; i < n; i++)
		ord[car2[i]] = i;
	int ans = 0;
	int j = 0;
	int best = n + 1, cancer = 0;
	for (int i = n; i > 0; i--) {
		while (j < n && a[car1[j]] >= i)
		{
			update(ord[car1[j]], { t[car1[j]], 1 });
			j++;
		}
		/*	for (int i = 0; i < n; i++)
		printf("%d ", query(i).first-query(i-1).first);
		printf("\n");
		for (int i = 0; i < n; i++)
		printf("%d ", query(i).second - query(i - 1).second);
		printf("\n");*/
		int lo = -1,
			hi = n - 1;
		while (lo < hi) {
			int mid = (lo + hi + 1) / 2;
			pli res = query(mid);
			if (res.first <= l)
				lo = mid;
			else
				hi = mid - 1;
		}
		pli res = query(lo);
		//printf("%d: %d\n", i, res.second);
		int alt = min(res.second, i);
		if (alt > ans) {
			cancer = res.second;
			ans = alt;
			best = i;
		}
	}
	printf("%d\n%d\n", ans, cancer);
	vector<pli> cust;
	for (int i = 0; i < n; i++)
		if (a[i] >= best)cust.push_back({ t[i], i + 1 });
	sort(cust.begin(), cust.end());
	for (int i = 0; i < cancer; i++)
		printf("%d ", cust[i].second);
	printf("\n");
	cin >> n;
}