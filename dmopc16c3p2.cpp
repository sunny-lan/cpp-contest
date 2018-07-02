#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

typedef long long ll;

int pre[MAXN];
int idx[MAXN];

int main() {
	memset(idx, -1, sizeof idx);

	int n, k, d; scan(n); scan(k); scan(d);
	int curr = 0;
	for (int i = 0; i < n; i++) {
		pre[i] = 1;
		char op; scanf(" %c", &op);
		if (op == 'T') {
			idx[i] = curr++;
		}
		else {
			int q; scan(q);
			pre[i] = q;
		}
	}

	for (int i = n - 1; i > 0; i--) {
		if (pre[i] == -1)
			pre[i - 1] = -1;
		else
			pre[i - 1] *= pre[i];

		if (pre[i - 1] > d)
			pre[i - 1] = -1;
	}

	for (int i = 0; i < n; i++) if (idx[i] != -1) {
		if (pre[i] == -1) printf("dust\n");
		else printf("%d\n", pre[i]);
	}

	cin >> n;
}