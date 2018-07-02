#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 101

int n;
double x[MAXN], y[MAXN];
bool eat[MAXN];

void chk(double cx, double cy)
{
	int mini = INT_MAX;
	vector<int> lst;
	for (int j = 0; j < n; j++) {
		int dx = x[j] - cx, dy = y[j] - cy;
		int dst = dx*dx + dy*dy;
		if (dst < mini)
			lst = vector<int>(), mini = dst;
		if (dst == mini)
			lst.push_back(j);
	}
	for (int i : lst)eat[i] = true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}

	for (int i = 0; i < n; i++) {
		chk(x[i], 0);
		for (int j = 0; j < n; j++)
			chk((x[i] + x[j]) / 2, 0);
	}
	
	for (int i = 0; i < n; i++)
		if (eat[i])
			printf("The sheep at (%.2lf, %.2lf) might be eaten.\n", x[i], y[i]);

	cin >> n;
}