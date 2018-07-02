#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int a[MAXN];

int main() {
	int n, x, k;
	scanf("%d %d %d", &n, &x, &k);
	ll res = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 0; i < n; i++) {

	}
	printf("%I64d\n", res);
}
