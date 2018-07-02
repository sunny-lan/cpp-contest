#include <bits/stdc++.h>
using namespace std;

#define MAXN 420

int m;
int cond[MAXN];

int dp[MAXN][MAXN];

int f(int l, int r) {
	ind++;
	l = (l + m) % m;
	r = (r + m) % m;

	if(l == r)
		return 0;
//    int &res=dp[l][r];
//    if(res!=-1)
//        return res;
	res = min(f(l + 1, r) + 1, f(l, r - 1) + 1);
	if(cond[l] == cond[r])
		res = min(res, f(l + 1, r - 1) + 1);
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	int prev = -1;
	int fst;
	for(int i = 0; i < n; i++) {
		int l;
		scanf("%d", &l);
		if(i == 0)
			fst = l;
		if(prev != -1 && l != prev)
			cond[m++] = l;
		prev = l;
	}
	if(prev != fst)
		cond[m++] = prev;
	int mini = INT_MAX;
	for(int st = 0; st < m; st++)
		memset(dp, -1, sizeof dp),
			   mini = min(mini, f(st - 1, st + 1) + 1);
	printf("%d %d", m / 2, mini);
}
