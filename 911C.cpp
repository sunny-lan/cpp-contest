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

#define MAXN 2250000

bool ye[MAXN];

bool shite(int ki, int ko, int ka) {
	memset(ye, false, sizeof ye);
	for (int i = 0; i < MAXN; i += ki)
		ye[i] = true;
	int tmp = 1;
	for (int i = 0; i < MAXN; i += tmp) {
		if (!ye[i])
			tmp = ko;
		ye[i] = true;
	}
	tmp = 1;
	for (int i = 0; i < MAXN; i += tmp) {
		if (!ye[i])
			tmp = ka;
		ye[i] = true;
	}
	for (int i = 0; i < MAXN; i++)
		if (!ye[i])return false;
	return true;
}

int main() {
	int kus[3]; for (int i = 0; i < 3; i++)scan(kus[i]);
	bool ans = false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)if (j != i)
			for (int k = 0; k < 3; k++)if (k != j && k != i)
				ans |= shite(kus[i], kus[j], kus[k]);
	if (ans)printf("YES");
	else printf("NO");
	cin >> kus[0];
}