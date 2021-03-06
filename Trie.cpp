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

#define MAXN 30000
#define MAXL 30

int ptr[26][MAXN*MAXL];
int eow[MAXN*MAXL];
int nw;

void init() {
	memset(ptr, -1, sizeof ptr);
	nw = 1;
}

void ins(const string& s, int i = 0, int j = 0) {
	if (i == s.length()) {
		eow[j]++;
		return;
	}
	int kust = s[i] - 'a';
	if (ptr[kust][j] == -1)
		ptr[kust][j] = nw++;
	//do update here
	ins(s, i + 1, ptr[s[i]][j]);
}

void traverse(const string& s, int i = 0, int j = 0) {
	if (i == s.length())return;
	int kust = s[i] - 'a';
	if (ptr[kust][j] == -1)return;
	//do proc here
	traverse(s, i + 1, ptr[kust][j]);
}

int main() {
}