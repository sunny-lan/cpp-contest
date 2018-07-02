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

#define MAXN 100010

int psa[MAXN];

int main() {
	int n, q; scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int x, y; scanf("%d %d", &x, &y);
		//y++;
		psa[x]++;
		psa[y]--;
	}
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum += psa[i];
		if (sum > 0)cnt++;
	}
	printf("%d %d\n", n - cnt, cnt);
	cin >> n;
}