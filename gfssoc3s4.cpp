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

#define MAXR 101
#define MAXC 23
#define MAXB 2746

int r, c;

int idx = 0;
int msk;
int fw[MAXB];
unordered_map<int, int> bw;

void g(int i, int b) {
	if (i == c)
		if(b!=0 && bw.find(b&msk)==bw.end())
		bw[b&msk] = idx, fw[idx++] = b&msk;
	if (i >= c)return;
	g(i + 1, b);
	g(i + 3, b | (2 << i));
}

bool dp[MAXR][MAXC][MAXB];

int main() {
	scan(r); scan(c);
	msk = (1 << c) - 1;
	g(0, 0);
	
	cin >> r;
}