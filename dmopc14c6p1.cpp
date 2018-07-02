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

string c[11];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		getline(cin, c[i]);
	}
	for (int i = 1; i < n; i++)
		if (c[i] == "Bessarion")
			if ((c[i - 1] == "Leslie" && (i + 1 == n || c[i + 1] == "Bayview")) || (c[i - 1] == "Bayview" && (i + 1 == n || c[i + 1] == "Leslie")))
			{
				printf("Y"); return 0;
			}
	printf("N");
}