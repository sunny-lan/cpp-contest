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

#define MAXN 1000010

int psa[MAXN];

int main() {
	int k; scan(k);
	for (int i = 0; i < k; i++) {
		int u; scan(u);
		psa[u]++;
	}
	for (int i = 0; i < MAXN - 1; i++)
		psa[i + 1] += psa[i];
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int f; scan(f);
		int numbad = psa[f];
		printf("%d\n", f - numbad);
	}
	cin >> n;
}