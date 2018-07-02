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

#define MAXN 200000

ll p[MAXN];

int* w;

int pred(int a, int b) {
	return w[a] < w[b];
}

int find_subset(int l, int u, int* _w, int n, int* result) {
	w = _w;
	for (int i = 0; i < n; i++)
		p[i] = i;

	sort(p, p + n, pred);

	int a = 0, b = -1;
	ll tot = 0;
	while (a < n && b < n) {
		if (tot < l)
			tot += w[p[++b]];
		else if (tot > u)
			tot -= w[p[a++]];
		else break;
	}
	if (tot<l || tot>u)
		return 0;
	for (int i = 0; i <= b - a; i++)
		result[i] = p[i + a];
	return b - a + 1;
}

int l = 14, u = 15;
int w1[] = { 5, 5, 6, 6 };
int r[100];

int main() {
	int cnt = find_subset(l, u, w1, sizeof w1 / sizeof(int), r);
	for (int i = 0; i < cnt; i++)
		cout << r[i] << " ";
	cout << endl;
	cin >> cnt;
}