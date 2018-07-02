#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string add(string &a, string &b) {
	string res = "";
	int cry = 0;
	for (int i = 0; i < max(a.length(), b.length()); i++) {
		int ta = i < a.length() ? a[i] - '0' : 0,
			tb = i < b.length() ? b[i] - '0' : 0;
		int s = cry + ta + tb;
		if (s >= 10)s -= 10, cry = 1;
		else cry = 0;
		res += s + '0';
	}
	if (cry == 1)
		res += '1';
	while (res[res.length() - 1] == '0')res.erase(res.length() - 1, 1);
	return res;
}

string sub(string &a, string &b) {
	string res = "";
	int brw = 0;
	for (int i = 0; i < max(a.length(), b.length()); i++) {
		int ta = i < a.length() ? a[i] - '0' : 0,
			tb = i < b.length() ? b[i] - '0' : 0;
		int s = ta - tb - brw;
		if (s < 0)s += 10, brw = 1;
		else brw = 0;
		res += s + '0';
	}
	if (brw==1)return sub(b, a) + '-';
	while (res[res.length() - 1] == '0')res.erase(res.length() - 1, 1);
	return res;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		bool an = false, bn = false;
		if (a[0] == '-')an = true,
			a.erase(0, 1);
		if (b[0] == '-')bn = true,
			b.erase(0, 1);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		if (an && bn)
			a = add(a, b) + '-';
		if (!an && bn)
			a = sub(a, b);
		if (an && !bn)
			a = sub(b, a);
		if (!an && !bn)
			a = add(a, b);

		reverse(a.begin(), a.end());
		if (a.length() == 0)a = "0";
		cout << a << endl;
	}
}