#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 200000

int k[MAXN];
int nxt[MAXN];
int cnt[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}

	int bs = sqrt(n);
	for (int i = n - 1; i >= 0; i--) {
		int nxtIdx = i + k[i];
		int nxtStart = min(n, (i / bs)*bs + bs);
		if (nxtIdx >= nxtStart) {
			nxt[i] = nxtIdx;
			cnt[i] = 1;
		}
		else {
			nxt[i] = nxt[nxtIdx];
			cnt[i] = cnt[nxtIdx] + 1;
		}
	}

	int	q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int op, x;
		scanf("%d %d", &op, &x);
		if (op == 1) {
			int res = 0;
			while (x < n) {
				res += cnt[x];
				x = nxt[x];
			}
			cout << res << endl;
		}
		else {
			scanf("%d", &k[x]);
			int start = (x / bs) * bs;
			int end = min(n, start + bs) - 1;
			for (int j = end; j >= start; j--) {
				int nxtIdx = j + k[j];
				if (nxtIdx > end) {
					nxt[j] = nxtIdx;
					cnt[j] = 1;
				}
				else {
					nxt[j] = nxt[nxtIdx];
					cnt[j] = cnt[nxtIdx] + 1;
				}
			}
		}
	}
	cin >> q;
}