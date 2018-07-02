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

#define MAXN 36

string sqr[MAXN];
int cnt[MAXN];

int conv(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sqr[i];
		memset(cnt, 0, sizeof cnt);
		for (char c : sqr[i]) {
			cnt[conv(c)]++;
			if (cnt[conv(c)] > 1)
			{
				printf("No\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < n; j++) {
			cnt[conv(sqr[j][i])]++;
			if (cnt[conv(sqr[j][i])] > 1)
			{
				printf("No\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (conv(sqr[0][i]) != i)
		{
			printf("Latin\n");
			return 0;
		}

	for (int i = 0; i < n; i++)
		if (conv(sqr[i][0]) != i)
		{
			printf("Latin\n");
			return 0;
		}

	printf("Reduced\n");
}