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

int tb[101][101];

int main() {
	int n;
outer:
	while (true) {
		scan(n);
		if (n == 0)break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scan(tb[i][j]); tb[i][j]--;
			}
		int i = -1;
		for (int x = 0; x < n; x++) {
			bool ident = true;
			for (int y = 0; y < n; y++) {
				if (tb[y][x] != y || tb[x][y] != y)
					ident = false;
				for (int z = 0; z < n; z++)
					if (tb[tb[x][y]][z] != tb[x][tb[y][z]])
					{
						printf("no\n");
						goto outer;
					}
			}
			if (ident)
				i = x;
		}
		if (i == -1) {
			printf("no\n");
			goto outer;
		}
		for (int x = 0; x < n; x++) {
			bool t2 = false;
			for (int inv = 0; inv < n; inv++)
				t2 |= tb[x][inv] == i && tb[inv][x] == i;
			if (!t2) {
				printf("no\n");
				goto outer;
			}
		}
		printf("yes\n");
	}
	cin >> n;
}