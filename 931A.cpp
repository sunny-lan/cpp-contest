#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int tmp = max(a, b);
	a = min(a, b);
	b = tmp;
	int mini = INT_MAX;
	for(int x = a; x <= b; x++) {
		int da = x - a,
			db = b - x;
		int ta = da * (da + 1) / 2,
			tb = db * (db + 1) / 2;
		mini = min(mini, ta + tb);
	}
	printf("%d\n", mini);
}
