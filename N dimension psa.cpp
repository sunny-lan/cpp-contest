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

vector<int> dimension;

int getIdx(const vector<int>& point) {
	int base = 1;
	int idx = 0;
	for (int i = 0; i < dimension.size(); i++) {
		idx += point[i] * base;
		base *= dimension[i];
	}
	return idx;
}

void construct(vector<int> &psa) {
	int d = 1;
	for (int i = 0; i < dimension.size(); i++) {
		int dim = dimension[i] * d;
		for (int j = d; j < psa.size(); j++)
			if ((j - d) / dim == j / dim)
				psa[j] += psa[j - d];
		d = dim;
	}
}

int main() {
	int n; scan(n);
	int base = 1;
	for (int i = 0; i < n; i++) {
		int sz; scan(sz);
		base *= sz;
		dimension.push_back(sz);
	}
	vector<int> psa(base);
	int q; scan(q);
	for (int i = 0; i < q; i++) {
		vector<int> point;
		for (int i = 0; i < n; i++) {
			int sz; scan(sz);
			point.push_back(sz);
		}
		psa[getIdx(point)]++;
	}
	construct(psa);
	scan(q);
	for (int i = 0; i < q; i++) {
		vector<int> point;
		for (int i = 0; i < n; i++) {
			int sz; scan(sz);
			point.push_back(sz);
		}
		printf("%d\n", psa[getIdx(point)]);
	}
	cin >> q;
}