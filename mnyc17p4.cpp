#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000

int v[MAXN];
int a[MAXN];
bool d[MAXN];

int dp[MAXN][MAXN];

int lst[MAXN];

int prv[MAXN];
int nxt[MAXN];

int f(int i, int j) {
	if (j - i <= 1)return 0;
	int res = dp[i][j];
	if (res != -1)return res;
	res = min(f(i + 1, j) + 1, f(i, j - 1) + 1);
	if (nxt[i] != -1 && nxt[i] < j)
		res = min(res, f(i, nxt[i]) + f(nxt[i], j));
	if (prv[j] != -1 && prv[j] > i)
		res = min(res, f(i, prv[j]) + f(prv[j], j));
	dp[i][j] = res;
	return res;
}

int v2[MAXN];

int n=7;

void dostuff() {
	for (int i = 0; i < n; i++)
		a[i] = i;

	int mini = INT_MAX;
	do {
		memset(d, false, sizeof d);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (d[a[i]])continue;
			for (int j = a[i] - 1; j >= 0; j--) {
				if (d[j])continue;
				if (v[j] == v[a[i]])d[j] = true;
				else break;
			}
			for (int j = a[i] + 1; j < n; j++) {
				if (d[j])continue;
				if (v[j] == v[a[i]])d[j] = true;
				else break;
			}
			cnt++;
			d[a[i]] = true;
		}
		mini = min(mini, cnt);
	} while (next_permutation(a, a + n));

	memset(dp, -1, sizeof dp);
	memset(lst, -1, sizeof lst);
	memset(prv, -1, sizeof prv);
	memset(nxt, -1, sizeof nxt);

	for (int i = 1; i < n + 1; i++)
		v2[i] = v[i - 1];

	v2[0] = 0;
	v2[n + 1] = n + 1;

	for (int i = 0; i < n + 2; i++) {
		prv[i] = lst[v2[i]];
		if (lst[v2[i]] != -1)
			nxt[lst[v2[i]]] = i;
		lst[v2[i]] = i;
	}

	int res = f(0, n + 1);
	if (res == mini) {
	}
	else {
		for (int i = 0; i < n; i++)
			printf("%d ", v[i]);
		printf("\n");
	}

}

void f(int idx) {
	if (idx == n)
		return dostuff();
	for (int i = 1; i <= n; i++) {
		v[idx] = i;
		f(idx + 1);
	}
}

int main() {
	f(0);
	cin >> n;
}