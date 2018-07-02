#include <bits/stdc++.h>
using namespace std;

#define MAXN 361

int a[MAXN];

int main() {
	int n;
	scanf("%d\n", &n);
	int mini = 360;
	int tot = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		tot += a[i];
		int tmp = tot;
		for(int j = 0; j <= i; j++) {
			int alt = 360 - tmp;
			mini = min(mini, abs(alt - tmp));
			tmp -= a[j];
		}
		int alt = 360 - tmp;
		mini = min(mini, abs(alt - tmp));
	}
	printf("%d\n", mini);
}
