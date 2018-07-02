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
	int n; cin >> n;
	string s; cin >> s;
	char last = 'X';//u=above, l=below
	int x = 0, y = 0;
	int cnt = 0;
	for (char c : s) {
		if (c == 'U') {
			if (x == y) {
				if (last == 'L')
					cnt++;
				last = 'X';
			}
			else {
				if (y > x)
					last = 'U';
				else
					last = 'L';
			}
			y++;
		}
		else {
			if (x == y) {
				if (last == 'U')
					cnt++;
				last = 'X';
			}
			else {
				if (y > x)
					last = 'U';
				else
					last = 'L';
			}
			x++;
		}
	}
	printf("%d\n", cnt);
	cin >> cnt;
}