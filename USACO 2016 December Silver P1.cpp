// USACO 2016 December Silver P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 100000

int nToL[MAXN];

int n;

int main()
{
	int  q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> nToL[i];
	}

	sort(begin(nToL), begin(nToL));

	for (int i = 0; i < n; i++) {
		cout << i << " -> " << nToL[i] << endl;
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		int lower = *upper_bound(begin(nToL), end(nToL), a);
		int upper = *lower_bound(begin(nToL), end(nToL), b);
		cout << "upper: " << upper << endl;
		cout << "lower: " << lower << endl;
		cout << "o:" << upper - lower << endl;

	}

	return 0;
}

