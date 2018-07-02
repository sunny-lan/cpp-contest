#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001
#define MAXB 13

int n;
string s;

char dp[MAXN][MAXB];

char f(int i, int j) {
	if(i > n)
		return '~';
	if(i == n)
		if(j == 0)
			return '`';
		else
			return '~';

	int &res = dp[i][j];
	if(res != -1)
		return res;

	return res;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = s.length();
}
