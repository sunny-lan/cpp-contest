#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int kust = m - 1;
	int tot = m * (n - 1) + (m - 1);
	if(k < kust) {
		int left = kust - k;
		printf("%d\n", tot - left * (n - 1));
	} else {
		printf("%d\n", tot - (k - kust));
	}
}
