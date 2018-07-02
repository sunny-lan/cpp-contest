#include <iostream>

using namespace std;

#define MAXN 200000

int n;
long k[MAXN];

bool updated[MAXN];
long dp[MAXN];

long f(long x) {
	if (x >= n)
		return 0;

	if (updated[x])
		return dp[x];

	long res = f(x + k[x]) + 1;
	dp[x] = res;
	updated[x] = true;

	return res;
}

int main() {
	cin >> n;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cin >> k[i];

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int op;
		cin >> op;
		long x;
		cin >> x;
		if (op == 1)
			cout << f(x) << endl;
		else {
			cin >> k[x];
			updated[x] = false;
		}
	}
	cin >> n;
}