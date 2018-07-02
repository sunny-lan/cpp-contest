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


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define INF 1000000
#define MAXN 150000

int n;
int v[3][MAXN];
int dp[1 << 3][MAXN][3];

int f(int b, int i, int curr) {
	if (i == n) {
		if (b == 0)return 0;
		else return INF;
	}

	int &res = dp[b][i][curr];
	if (res != -1)
		return res;

	res = f(b&~(1 << curr), i + 1, curr);
	if (!((b>>curr)&1)) // if bit is 0, means 1 has already been traversed
		for (int j = 0; j < 3; j++) if ((b >> j) & 1)
			res = min(res, f(b&~(1 << j), i + 1, j));

	res += v[curr][i];

	return res;
}

int main() {
	memeset(dp, -1, sizeof dp);
	scan(n);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			scan(v[i][j]);
	cout << min(f((1 << 3) - 1, 0, 0), min(f((1 << 3) - 1, 0, 1), f((1 << 3) - 1, 0, 2))) << endl;
	cin >> n;
}