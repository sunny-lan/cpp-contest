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

#define MAXN 100000

int p[MAXN];

int f(int x) {
	if (p[x] == x)return x;
	return p[x] = f(p[x]);
}

vector<pair<int, pii>> edges;

int main() {
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++) {
		if (i + k < n)
			edges.push_back({ 0,{ i,i + k } });
		p[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		int w; scan(w);
		edges.push_back({ w,{i, i + 1} });
	}

	sort(edges.begin(), edges.end());

	int tot = 0;

	for (auto edge : edges) {
		pii ep = edge.second;
		if (f(ep.first) == f(ep.second))continue;
		tot += edge.first;
		p[f(ep.first)] = p[f(ep.second)];
	}

	printf("%d\n", tot);
	cin >> tot;
}