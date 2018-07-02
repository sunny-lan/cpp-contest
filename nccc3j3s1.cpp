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

int cnt[26];

int main() {
	string s; cin >> s;
	for (char c : s) {
		cnt[c - 'a']++;
	}
	int mini = INT_MAX;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			int tot = s.length();
			tot -= cnt[i];
			if (j != i)
				tot -= cnt[j];
			mini = min(mini, tot);
		}
	}
	printf("%d", mini);
}