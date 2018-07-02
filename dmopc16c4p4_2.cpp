#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 100001

int n, bs;

int series[MAXN];

int ptr[MAXN];
int start[MAXN];
int stop[MAXN];

int cnt[MAXN];
int ans = 0;

int out[MAXN];

bool cmp(int a, int b) {
	int ba = start[a] / bs;
	int bb = start[b] / bs;
	if (ba == bb)
		return stop[a] < stop[b];
	return ba < bb;
}

void add(int idx) {
	if (idx < 0 || idx >= n)
		return;
	if (cnt[series[idx]] > 0 && cnt[series[idx]] % 2 == 0)
		--ans;
	++cnt[series[idx]];
	if (cnt[series[idx]] > 0 && cnt[series[idx]] % 2 == 0)
		++ans;
}

void remove(int idx) {
	if (idx < 0 || idx >= n)
		return;
	if (cnt[series[idx]] > 0 && cnt[series[idx]] % 2 == 0)
		--ans;
	--cnt[series[idx]];
	if (cnt[series[idx]] > 0 && cnt[series[idx]] % 2 == 0)
		++ans;
}

int main() {
	ios::sync_with_stdio(false);
	int qC;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> series[i];
		--series[i];
	}

	cin >> qC;
	for (int i = 0; i < qC; i++) {
		cin >> start[ptr[i] = i] >> stop[i];
		--start[i]; --stop[i];
	}

	bs = (int)sqrt(n);

	sort(ptr, ptr + qC, cmp);

	int l = 0;
	int r = -1;

	for (int i = 0; i < qC; i++) {
		int p = start[ptr[i]];
		int q = stop[ptr[i]];

		if (l < p)
			while (l < p) 
				remove(l++);
		else
			while (l > p)
				add(--l);

		if (r > q)
			while (r > q) 
				remove(r--);
		else
			while (r < q)
				add(++r);

		out[ptr[i]] = ans;
	}

	for (int i = 0; i < qC; i++)
		cout << out[i] << endl;

	cin >> n;
}