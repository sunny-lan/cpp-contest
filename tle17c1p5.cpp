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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1001

int cake[MAXN][MAXN];
int r, c;

void dfs(int i, int j) {
	if (i < 0 || j < 0 || i >= r || j >= c)return;
	if (cake[i][j] == 1)return;
	cake[i][j] = 1;
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}

int main() {
	scan(r); scan(c);
	for (int i = 0; i < r; i++) {
		int c1, d1; scan(c1); scan(d1);
		c1--, d1--;
		for (int j = 0; j < c; j++) {
			if (j >= c1 && j <= d1)
				cake[i][j] = 2;
			else
				cake[i][j] = 1;
		}
	}

	for (int i = 0; i < c; i++) {
		int c1, d1; scan(c1); scan(d1);
		c1--, d1--;
		for (int j = 0; j < r; j++) {
			if (j >= c1 && j <= d1) {
				if (cake[j][i] == 1) {
					cout << "nonsense" << endl;
					cout << j + 1 << " " << i + 1 << endl;
					return 0;
				}
				cake[j][i] = 2;
			}
			else {
				if (cake[j][i] == 2) {
					cout << "nonsense" << endl;
					cout << j + 1 << " " << i + 1 << endl;
					return 0;
				}
				cake[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (cake[i][j] == 2) {
				dfs(i, j);
				goto nexT;
			}

	nexT:
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (cake[i][j] == 2) {
				cout << "nonsense" << endl;
				cout << "unconnected" << endl;
				return 0;
			}
	cout << "sense" << endl;
	cin >> r;
}