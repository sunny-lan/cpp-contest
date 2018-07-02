#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool pred(string &a, string &b) {
	return a.length() > b.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_map<string, vector<string>> phns;
	for (int i = 0; i < n; i++) {
		string nm; int m; cin >> nm >> m;
		for (int j = 0; j < m; j++) {
			string phn; cin >> phn;
			phns[nm].push_back(phn);
		}
	}
	cout << phns.size() << endl;
	for (auto entry : phns) {
		vector<string> cust=entry.second;
		vector<string> res;
		sort(cust.begin(), cust.end(), pred);
		for (int j = 0; j < cust.size(); j++) {
			for (int k = 0; k < j; k++) {
				for (int l = 0; l < cust[j].length(); l++)
					if (cust[j][cust[j].length() - l - 1] != cust[k][cust[k].length() - l - 1])
						goto nomatch;
				goto match;
			nomatch:continue;
			}
			res.push_back(cust[j]);
		match:continue;
		}
		if (res.empty())continue;
		cout << entry.first << " " << res.size();
		for (string s : res)cout << " " << s;
		cout << endl;
	}
	cin >> n;
}