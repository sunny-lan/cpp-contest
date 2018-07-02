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

#define MAXN 1000
int p[MAXN];
int deg[MAXN];
int cnt[MAXN];

int main() {
	int n; scan(n);
	for (int i = 1; i <= n - 1; i++) {
		 scan(p[i]);
		p[i]--;
		deg[p[i]]++;
	}
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			cnt[p[i]]++;
	for(int i=0;i<n;i++)
		if (deg[i] != 0 && cnt[i] < 3)
		{
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	cin >> n;
}