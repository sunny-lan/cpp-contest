#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 101

int x[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	sort(x, x + n);

	double mini = INT_MAX;

	for (int i = 1; i < n - 1; i++) {
		double l = x[i - 1], r = x[i + 1];
		double c = x[i];
		double ml = (c + l) / 2,
			mr = (c + r) / 2;
		mini = min(mini, mr - ml);
	}

	printf("%.1lf\n", mini);
	cin >> mini;
}