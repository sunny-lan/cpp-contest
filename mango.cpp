#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000

typedef pair<int, int> pii;

int a[MAXN];

int ptr[MAXN];
pii qu[MAXN];
int n,bs;
bool pred(int _a, int _b) {
	pii a = qu[_a], b = qu[_b];
	int ba = a.first / bs,
		bb = b.first / bs;
	if (ba == bb)
		return a.second < b.second;
	return ba < bb;
}

int cnt = 0;
int freq[MAXN];

int ans[MAXN];

int main() {
	scanf("%d", &n); bs = sqrt(n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++)
		scanf("%d %d", &qu[i].first, &qu[i].second), ptr[i] = i, qu[i].first--;
	sort(ptr, ptr + q, pred);
	int cl = 0, cr = 0;
	for (int i = 0; i < q; i++) {
		int dl = qu[ptr[i]].first,
			dr = qu[ptr[i]].second;

		while (cr < dr) {
			freq[a[cr]]++;
			if (freq[a[cr]] > 1) {
				if (freq[a[cr]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
			cr++;
		}

		while (cl > dl) {
			cl--;
			freq[a[cl]]++;
			if (freq[a[cl]] > 1) {
				if (freq[a[cl]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
		}

		while (cl < dl) {
			freq[a[cl]]--;
			if (freq[a[cl]] > 0) {
				if (freq[a[cl]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
			cl++;
		}

		while (cr > dr) {
			cr--;
			freq[a[cr]]--;
			if (freq[a[cr]] > 0) {
				if (freq[a[cr]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
		}
		ans[ptr[i]] = cnt;
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}