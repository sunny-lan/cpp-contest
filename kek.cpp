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

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 2000001

bool v[MAXN];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		x--;
		v[x] = true;
	}

	vector<pii> stu;
	for (int i = 0; i < k + 1; ++i) {
		int x;
		scanf("%d", &x);
		x--;
		stu.push_back({ x, i });
	}

	while (stu.size() > 1) {
		for (int i = stu.size() - 1; i >= 0; i--) {
			if (v[stu[i].f]) {
				v[stu[i].f] = false;
				stu.erase(stu.begin() + i);
			}
		}
		if (stu.size() == 1)break;
		for (int i = stu.size() - 1; i >= 0; i--) {
			stu[i].f++;
			if (stu[i].f == n)
				stu[i].f = 0;
		}
	}

	printf("%d\n",stu.front().s+1);

	return 0;
}
