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

#define MAXN 110

string map[MAXN];
int dp[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int rows, cols; cin >> rows >> cols;
		if (rows == 0 && cols == 0)
			break;
		for (int row = 0; row < rows; row++) {
			cin >> map[row];
			for (int col = 0; col < cols; col++) {
				dp[row][col] = -1000000;
				if (map[row][col] == '.')map[row][col] = '0';
			}
			dp[row][cols] = -1000000;
		}
		dp[rows - 1][0] = 0;
		for (int col = 0; col < cols; col++) {
			for (int row = 0; row < rows; row++) {
				int sum = 0;
				for (int nxtrow = row; nxtrow < rows; nxtrow++)
				{
					if (map[nxtrow][col] == '*')break;
					sum += map[nxtrow][col] - '0';
					dp[nxtrow][col + 1] = max(dp[nxtrow][col + 1], dp[row][col] + sum);
				}
				sum = 0;
				for (int nxtrow = row; nxtrow >= 0; nxtrow--)
				{
					if (map[nxtrow][col] == '*')break;
					sum += map[nxtrow][col] - '0';
					dp[nxtrow][col + 1] = max(dp[nxtrow][col + 1], dp[row][col] + sum);
				}
			}
		}
		printf("%d\n", dp[rows - 1][cols]);
	}
}