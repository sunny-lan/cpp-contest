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

#define MAXN 10000

vector<int> ch[MAXN];

int c[MAXN];

int cnt(int i, int j) {
	int r = 0;
	if (j != c[i])r++;
	for (int k : ch[i])
		r += cnt(k, c[i]);
	return r;
}

int main() {
	int n; scan(n);
	for (int i = 1; i <= n - 1; i++) {
		int p; scan(p);
		p--;
		ch[p].push_back(i);
	}
	for (int i = 0; i < n; i++)
		scan(c[i]);
	printf("%d\n", cnt(0, -1));
}