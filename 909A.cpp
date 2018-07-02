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

int main() {
	string first, last; cin >> first >> last;
	vector<string> lst;
	for (int i = 1; i <= first.length(); i++) {
		for (int j = 1; j <= last.length(); j++) {
			string t = first.substr(0, i)+last.substr(0, j);
			lst.push_back(t);
		}
	}
	sort(lst.begin(), lst.end());
	cout << lst[0] << endl;
	cin >> first;
}