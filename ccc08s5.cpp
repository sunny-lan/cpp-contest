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
using namespace std;

#define memeset memset

template<typename T>
inline T INF(T a) { return a == -1 ? INT_MAX : a; }
inline int _INF(int a) { return a == INT_MAX ? -1 : a; }

template<typename T>
inline T INF_MAX(T a, T b) { return INF(a) > INF(b) ? a : b; }

template<typename T>
inline T INF_MIN(T a, T b) { return INF(a) < INF(b) ? a : b; }


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<bool, bool> pbb;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 31

int dp[2][MAXN][MAXN][MAXN][MAXN];
int react[5][4] = {
	{2,1,0,2},
	{1,1,1,1},
	{0,0,2,1},
	{0,3,0,0},
	{1,0,0,1}
};

//returns p1 has g win
int f(int p, int a[4]) {
	int res = dp[p][a[0]][a[1]][a[2]][a[3]];
	if (res != -1)return res;

	bool win;
	if (p == 0)
		win = false;//or identity
	else
		win = true;//and identity
	int alt=-1;
	for (int r = 0; r < 5; r++) {
		int left[4]; memcpy(left, a, sizeof left);
		for (int i = 0; i < 4; i++) {
			if (a[i] < react[r][i])goto outer;
			left[i] -= react[r][i];
		}
		alt = f(p == 0 ? 1 : 0, left);
		if (p == 0) {
			//curr player is p1
			//p1 may pick any path that wins
			win |= alt;
		}
		else {
			//vice versa
			win &= alt;
		}
	outer:continue;
	}

	return dp[p][a[0]][a[1]][a[2]][a[3]] = win ? 1 : 0;
}

int main() {
	memset(dp, -1, sizeof dp);
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int a[4]; scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
		int res = f(0, a);
		if (res == 1)
			printf("Patrick\n");
		else
			printf("Roland\n");
	}
	cin >> n;
}