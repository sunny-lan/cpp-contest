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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	unordered_map<string, string > mp;
	for (int i = 0; i < n; i++) {
		string nm, ip; cin >> nm >> ip;
		mp[ip] = nm;
	}
	for (int i = 0; i < m; i++) {
		string cmd, ip; cin >> cmd >> ip;
		ip = ip.substr(0, ip.length() - 1);
		cout << cmd << " " << ip << "; #" << mp[ip] << endl;
	}
	cin >> n;
}