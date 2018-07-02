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

#define MAXN 2018

int map[MAXN][MAXN];
int psaH[MAXN][MAXN];
int psaV[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string line; cin >> line;
		for (int j = 0; j < m; j++) {
			if (line[j] == '*')
				map[i][j] = 1;
			psaH[i][j + 1] = psaH[i][j] + map[i][j];
			psaV[i + 1][j] = psaV[i][j] + map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j + k <= m; j++) 
			if (psaH[i][j + k] == psaH[i][j])
				cnt++;

	if(k!=1)
	for (int i = 0; i < m; i++)
		for (int j = 0; j + k <= n; j++)
			if (psaV[j+k][i] == psaV[j][i])
				cnt++;

	printf("%d", cnt);
	cin >> n;
}