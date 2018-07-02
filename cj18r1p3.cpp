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
#include <set>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 1001

int rows, cols;
int v[MAXN][MAXN];
bool pl[MAXN][MAXN];
set<pair<int, pii>> kust;
void upd(int r, int c) {
	pair<int, pii> fnd = { v[r][c], {r,c} };
	if (kust.count(fnd) == 0)return;
	kust.erase(fnd);
	fnd.first++, v[r][c]++;
	if(fnd.first<9)
	kust.insert(fnd);
}
void plant(int r, int c) {
	if (pl[r][c])return;
	for (int a = r - 1; a <= r + 1; a++)
		for (int b = c - 1; b <= c + 1; b++)
			if (a > 0 && b > 0 && a < rows - 1 && b < cols - 1)
				upd(a, b);
	pl[r][c] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		kust.clear();
		memset(pl, false, sizeof pl);
		memset(v, 0, sizeof v);

		int a; cin >> a;
		rows = sqrt(a),cols=(a+rows-1)/rows;
		for (int i = 1; i < rows - 1; i++)
			for (int j = 1; j < cols - 1; j++)
				kust.insert({ 0, {i,j} });
		while (!kust.empty()) {
			auto ks = kust.begin();
			cout << ks->second.first + 1 << " " << ks->second.second + 1 << endl;
			int i, j; cin >> i >> j;
			i--, j--;
			if (i < 0 || j < 0)goto outer;
			plant(i, j);
		}
	outer:continue;
	}
}
