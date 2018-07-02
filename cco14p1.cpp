#include <bits/stdc++.h>
using namespace std;

#define MAXN 2001

string mp[MAXN];

int n;
int dp[MAXN][MAXN];

int f(int i, int j) {
	if(i >= n)
		return 0;
	if(j < 0 || j >= n)
		return 0;
	int &res = dp[i][j];
	if(res != -1)
		return res;
	if(mp[i][j] == '#')
		res =  min(f(i + 1, j - 1), min(f(i + 1, j), f(i + 1, j + 1)))+1;
	else
		res = 0;
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> mp[i];
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        res+=f(i,j);
    printf("%d", res);
}
