#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1000

bool map[MAXN][MAXN];

int main() {
	int k; scan(k);
	for (int t = 0; t < k; t++) {
		int n, m; scan(n); scan(m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char c; scanf(" %c", &c);
				map[i][j] = (c == 'F');
			}
	}
}