#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int m, n;
string a[40], b[40];
string sa = "";
string sb = "";
vector<int> res;
bool dfs(int k) {
	int ola = sa.length(), olb = sb.length();
	for (int i = 0; i < min(ola, olb); i++)
		if (sa[i] != sb[i])
			return false;
	if (k >= m)return false;
	if (k > 0 && ola == olb)return true;
	for (int i = 0; i < n; i++) {
		sa += a[i], sb += b[i];
		if (dfs(k + 1))
		{
			res.push_back(i);
			return true;
		}
		sa.resize(ola), sb.resize(olb);
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	dfs(0);
	if (res.empty())
		printf("No solution.\n");
	else
	{
		reverse(res.begin(), res.end());
		printf("%d\n", res.size());
		for (int i : res)printf("%d\n", i + 1);
	}
	cin >> n;
}