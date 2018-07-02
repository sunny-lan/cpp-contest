#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 10010

int tree[MAXN * 2];
int cnt[MAXN * 2];

string expr;

void parse(int i, int j, int k = 1) {
	if (expr[i] == '(') {
		i++, j--;
		for (int l = i; l < j; l++)
			if (expr[l] == '?')
			{
				tree[k] = -2;
				parse(i, l, k * 2);
				parse(l + 1, j, k * 2 + 1);
				cnt[k] = cnt[k * 2] + cnt[k * 2 + 1] + 1;
				break;
			}
	}
	else {
		tree[k] = atoi(expr.substr(i, j - i).c_str());
	}
}

int p, m;
int dp[110][MAXN * 2];

int f(int j, int i = 1) {
	int &res = dp[j][i];
	if (res != -1)return res;
	if (tree[i] == -2) {
		if (p < m) {
			int cp = j, cm = cnt[i] - cp;

		}
		else {
			int cm = j, cp = cnt[i] - cm;

		}
	}
	else {
		if (j == 0)return tree[i];
		else return INT_MIN;
	}
	return res;
}

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> expr >> p >> m;
	parse(0, expr.length());
	printf("%d\n", f(min(p, m)));
}