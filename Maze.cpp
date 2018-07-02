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

#define MAXN 1000

char map[MAXN][MAXN];
int n, m;
int visited[MAXN][MAXN];

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return;
	if(map[x][y]=='F')
	if (visited[x][y] == 4)return;
	visited[x][y]++;

	visited[x][y]--;
}

int main() {
	scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = getchar();
		}
		getchar();
	}


}