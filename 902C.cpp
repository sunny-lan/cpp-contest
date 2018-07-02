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

#define MAXH 100010
vector<int> adja[MAXH];
vector<int> adjb[MAXH];

int main() {
	int h; scan(h);
	int prv; scan(prv);
	int idx = 1;
	adja[0].push_back(0);
	adjb[0].push_back(0);
	bool diverged = false;
	for (int i = 1; i <= h; i++) {
		int a; scan(a);
		if (diverged || prv==1 || a==1) {
			for (int j = 0; j < a; j++) {
				adja[i].push_back(idx);
				adjb[i].push_back(idx);
			}
		}
		else {
			for(int j=0;j<a;j++)
				adja[i].push_back(idx);
			for (int j = 0; j < a - 1; j++)
				adjb[i].push_back(idx);
			adjb[i].push_back(idx + 1);
			diverged = true;
		}
		idx += prv;
		prv = a;
	}
	if (!diverged) {
		printf("perfect");
		return 0;
	}
	printf("ambiguous\n");
	for (int i = 0; i <= h; i++)
		for (int j : adja[i])
			printf("%d ", j);
	printf("\n");
	for (int i = 0; i <= h; i++)
		for (int j : adjb[i])
			printf("%d ", j);
	cin >> h;
}