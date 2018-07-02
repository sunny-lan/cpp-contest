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

int cnts[26];
int cntt[26];

int main() {
	string s, t; cin >> s >> t;
	int n = s.length(), m = t.length();
	for (int i = 0; i < m; i++)cntt[t[i] - 'a']++;
	int q = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '?')q++;
		else
			cnts[t[i] - 'a']++;

	int mini = INT_MAX;
	for (int i = 0; i < 26; i++) 
		mini = min(mini, cnts[i] / cntt[i]);
	
	
}