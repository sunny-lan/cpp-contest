#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

int n, *x, *y;

int clcbst() {
	double maxi = -1, h = 0;
	ll bst, hmod = 1;
	for(int i = 0; i < n; i++)
	{
		h += log(x[i]);
		hmod = hmod * x[i] % MOD;
		double alt = h + log(y[i]);
		if(alt > maxi)
		{
			maxi = alt;
			bst = hmod * y[i] % MOD;
		}
	}
	return bst;
}

int init(int N, int X[], int Y[]) {
	n = N, x = X, y = Y;
	return clcbst();
}

int updateX(int pos, int val) {
	x[pos] = val;
	return clcbst();
}

int updateY(int pos, int val) {
	y[pos] = val;
	return clcbst();
}
