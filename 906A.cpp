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

bool cust[26];

bool tmp[26];

int main() {
	int n; cin >> n;
	bool cancer = false;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		char a; string b;
		scanf(" %c", &a);
		cin >> b;
		if (a == '.') {
			for (char c : b)cust[c-'a'] = true;
		}
		else if (a == '!') {
		memset(tmp, false, sizeof tmp);
		//bool ca = true;
		for (char c : b) tmp[c - 'a'] = true;
			for (int j = 0; j < 26;j++)if (!tmp[j])
				cust[j] = true;
			if (cancer)
				ans++;
		}
		else {
			if ( cancer && i != n - 1)ans++;
			cust[b[0]-'a'] = true;
		}
		int cnt = 0;
		for (int j = 0; j < 26;j++)
			if (!cust[j])
				cnt++;
		if (cnt == 1)cancer = true;
	}
	cout << ans << endl;
	cin >> n;
}