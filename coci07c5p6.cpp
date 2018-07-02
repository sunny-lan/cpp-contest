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

#define MAXN 30000

#define NUM int

//template begin
NUM bit[MAXN];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, NUM v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y < MAXN; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

unordered_map<string, int> ord;
pair<pii, string> cancer[MAXN];
string strs[MAXN];
int ptr[MAXN];
bool pred(int x, int y) {
	return strs[x] < strs[y];
}
int ord2[MAXN];

int ans[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
		ptr[i] = i;
		ord[strs[i]] = i;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string s; cin >> s;
		int idx = n;
		if (ord.find(s) != ord.end())
			idx = ord[s];
		cancer[i] = { { idx, i}, s };
	}
	sort(cancer, cancer + q);
	sort(ptr, ptr + n, pred);
	for (int i = 0; i < n; i++)
		ord2[ptr[i]] = i;
	int ptx = 0;
	for (int i = 0; i < q; i++) {
		while (ptx < n && ptx <= cancer[i].first.first)
			update(ord2[ptx], 1), ptx++;
		int lox = 0,
			hix = n;
		for (int l = 0; l < cancer[i].second.length(); l++) {
			int lo = lox,
				hi = hix;
			while (lo < hi) {
				int mid = (hi + lo) / 2;
				if (l < strs[ptr[mid]].length() && strs[ptr[mid]][l] >= cancer[i].second[l])
					hi = mid;
				else
					lo = mid + 1;
			}
			lox = lo;
			hi = hix;
			while (lo < hi) {
				int mid = (hi + lo) / 2;
				if (l < strs[ptr[mid]].length() && strs[ptr[mid]][l] > cancer[i].second[l])
					hi = mid;
				else
					lo = mid + 1;
			}
			hix = lo;
			ans[cancer[i].first.second] += query(hix - 1) - query(lox - 1);
		}
		ans[cancer[i].first.second] += cancer[i].first.first;
		if (cancer[i].first.first != n)ans[cancer[i].first.second]++;

	}
	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	printf("\n");
	cin >> n;
}