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

#define MAXN 1010

int r, c;
int value[MAXN][MAXN];
int prefix[4][MAXN][MAXN];

int main() {
	scan(r); scan(c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char c = getchar();
			if (c == 'X')
				value[i][j]++;
		}
		if (i != r - 1)
			getchar();
	}

	memcpy(prefix[0], value, sizeof value);

	for (int row = 0; row < r; row++)
		for (int col = 0; col < c; col++)
			prefix[0][row][col + 1] |= prefix[0][row][col];


	memcpy(prefix[1], value, sizeof value);

	for (int row = 0; row < r; row++)
		for (int col = c; col >= 1; col--)
			prefix[1][row][col - 1] |= prefix[1][row][col];

	memcpy(prefix[2], value, sizeof value);

	for (int col = 0; col < c; col++)
		for (int row = 0; row < r; row++)
			prefix[2][row + 1][col] |= prefix[2][row][col];

	memcpy(prefix[3], value, sizeof value);

	for (int col = 0; col < c; col++)
		for (int row = r; row >= 1; row--)
			prefix[3][row - 1][col] |= prefix[3][row][col];

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int row, col; scan(col); scan(row);
		row--, col--;
		bool res = false;
		for (int j = 0; j < 4; j++)
			res |= prefix[j][row][col];
		if (res)printf("Y\n");
		else printf("N\n");
	}
	cin >> q;
}