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

#define MAXN 50

string maze[MAXN];

pii dirs[] = { {0,1}, {0,-1}, {1,0},{-1,0} };
int ord[] = { 0,1,2,3 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	pii st;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
		for (int j = 0; j < m; j++)
			if (maze[i][j] == 'S')
				st = { i,j };
	}
	string s; cin >> s;
	int cnt = 0;
	do {
		pii loc = st;
		for (char c : s) {
			pii delt = dirs[ord[c - '0']];
			loc.first += delt.first, loc.second += delt.second;
			if (loc.first < 0 || loc.second < 0 || loc.first >= n || loc.second >= m)break;
			char df = maze[loc.first][loc.second];
			if (df == '#')break;
			if (df == 'E') {
				cnt++;
				break;
			}
		}
	} while (std::next_permutation(ord, ord + 4));
	printf("%d", cnt);
}