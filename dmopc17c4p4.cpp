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

#define MAXN 1000001

int a[MAXN];
bool used[MAXN];
int out[MAXN];

int main() {
	memset(out, -1, sizeof out);
	int n; scanf("%d", &n);
	int prev = -1; bool sm = true;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (prev == -1)
			prev = a[i];
		if (a[i] != prev)
		{
			sm = false;
		}
	}
	if (sm) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (used[a[i]])continue;
		int j = i;
		while (a[j] == a[i]) {
			j--;
			if (j < 0)j += n;
		}
		out[j] = a[i];
		used[a[i]] = true;

	}

	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (used[i])continue;
		while (out[j] != -1)
			j++;
		out[j] = i;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", out[i]);
	cin >> n;
}