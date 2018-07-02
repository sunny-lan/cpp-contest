#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

#define MAXN 150000
#define MAXBS 400

int a[MAXN];
int lmap[MAXN];
int lcust[MAXN];
vector<int> lines[MAXN];

int s[MAXBS];

int lbound[MAXBS][MAXN];
int rbound[MAXBS][MAXN];

int shf[MAXN];


int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	int bs = sqrt(n);

	memset(lbound, -1, sizeof(lbound));
	memset(rbound, -1, sizeof(rbound));

	for (int i = 0; i < n; i++) {
		int line;
		scanf("%d", &line);
		int idx = lines[--line].size();
		lines[line].push_back(i);
		lmap[i] = idx;
		lcust[i] = line;
		int tmp = lbound[i / bs][line];
		if (tmp == -1)
			tmp = INT_MAX;
		lbound[i / bs][line] = min(tmp, idx);
		rbound[i / bs][line] = max(rbound[i / bs][line], idx);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s[i / bs] += a[i];
	}

	int numblocks = n / bs;


	for (int i = 0; i < q; i++) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r;
			scanf("%d %d", &l, &r);
			l--; r--;
			int startb = l / bs;
			int endb = r / bs;
			int res = 0;
			for (int j = startb; j < endb; j++)
				res += s[j];
			for (int j = l; j < startb*bs; j++)
				res += a[lines[lcust[j]][(lmap[j] - shf[lcust[j]]+ lines[lcust[j]].size()) % lines[lcust[j]].size()]];
			for (int j = endb*bs; j <= r; j++)
				res += a[lines[lcust[j]][(lmap[j] - shf[lcust[j]]+ lines[lcust[j]].size()) % lines[lcust[j]].size()]];
			cout << res << endl;
		}
		else {
			int x;
			scanf("%d", &x);
			int loop = lines[--x].size();
			for (int j = 0; j <= numblocks; j++) {
				int l = lbound[j][x];
				if (l != -1) {
					s[j] -= a[lines[x][(rbound[j][x] + shf[x]) % loop]];
					s[j] += a[lines[x][(lbound[j][x] - 1 + shf[x] + loop) % loop]];
				}
			}
			shf[x]++;
			shf[x] %= loop;
		}
	}

}