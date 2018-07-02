#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; string s; cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int l, r; string c1l, c2l; cin >> l >> r >> c1l >> c2l;
		l--;
		char c1 = c1l[0], c2 = c2l[0];
		for (int j = l; j < r; j++)
			if (s[j] == c1)
				s[j] = c2;
	}
	cout << s << endl;
	cin >> n;
}