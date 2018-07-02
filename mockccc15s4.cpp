#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ull;

#define MAXN 100005

ull destroyed[MAXN];
ull pending[MAXN];

ull d[MAXN];
ull w[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	memset(d, 0, sizeof d);
	memset(w, 0, sizeof w);
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> w[i];
		destroyed[i] = pending[i] = LONG_MAX;
	}
	destroyed[n+1] = pending[n+1] = LONG_MAX;

	destroyed[1] = 0;
	
	for (int i = 1; i <= n; i++) {
		if (destroyed[i] != LONG_MAX) {
			destroyed[i + 1] = min(destroyed[i + 1], destroyed[i] + max(0ll,d[i] - w[i - 1]));
			pending[i + 1] = min(pending[i + 1], destroyed[i] + max(0ll,max(0ll,d[i] - w[i - 1]) - w[i + 1]));
		}

		if (pending[i] != LONG_MAX) {
			destroyed[i + 1] = min(destroyed[i + 1], pending[i] + d[i]);
			pending[i + 1] = min(pending[i + 1], pending[i] + max(0ll,d[i] - w[i + 1]));
		}
	}

	cout << destroyed[n+1] << endl;

	cin >> n;
}