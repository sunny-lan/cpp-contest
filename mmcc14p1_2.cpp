#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 11
#define MAXS 15
#define LIM 1<<11

int m[MAXN];
int d[12][LIM][20];

int n;

bool chk(int v, int i) {
	return (v >> i) & 1;
}

int set(int v, int i) {
	return v ^ (1 << i);
}

int f(int u, int c, int k) {
	int res = d[u][c][k];
	if (res != -1)
		return res;

	res = 0;

	if (c == 0)
		res = (m[u] + k)*(m[u] + k) + k;
	else

		for (int a = 0; a < n; a++) {
			if (!chk(c, a) || a == u) continue;
			for (int b = a + 1; b < n; b++) {
				if (!chk(c, b) || b == u) continue;
				int tmp = set(set(c, a), b);

				for (int i = 0; i <= k; i++) {
					for (int j = 0; j + i <= k; j++) {
						int cc = k - (j + i);
						res = max(res,
							min(
								f(a, tmp, i)*f(b, 0, j),
								(m[u] + cc)*(m[u] + cc)
							) + cc
						);
					}
				}
			}
		}

	d[u][c][k] = res;
	return res;
}

int main() {
	memset(d, -1, sizeof(d));

	int s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &m[i]);

	int maxi = 0;
	for (int i = 0; i < n; i++)
		maxi = max(maxi, f(i, ((1 << n) - 1) ^ (1 << i), s));

	cout << maxi << endl;

	cin >> n;
}