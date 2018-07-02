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

#define INF 10000
#define MAXD 1010
#define MAXS 5010

int dp[MAXD][MAXS];
pii ptr[MAXD][MAXS];

int d, s;
string a;

int nxt1[MAXD];

int f(int i, int j) {
	if (j > s)return INF;
	if (i == d) {
		if (j == s)return 0;
		else return INF;
	}
	int res = dp[i][j];
	if (res != -1)
		return res;
	res = INF;
	int curr = 0;
	ptr[i][j] = { d, -1 };
	for (int k = nxt1[i]; k < d && k < nxt1[i] + 5; k++)
	{
		curr *= 10;
		curr += a[k] - '0';
		int alt = f(k + 1, j + curr) + 1;
		if (alt < res)
			res = alt,
			ptr[i][j] = { k + 1, j + curr };
	}
	return dp[i][j] = res;
}

int main() {
	memset(dp, -1, sizeof dp);
	char c;
	while ((c = getchar()) != '=') a += c;
	d = a.length();
	queue<int> idx;
	for (int i = 0; i < d; i++) {
		if (a[i] == '0')
			idx.push(i);
		else {
			nxt1[i] = i;
			while (!idx.empty())
				nxt1[idx.front()] = i, idx.pop();
		}
	}
	while (!idx.empty())
		nxt1[idx.front()] = d-1, idx.pop();
	scan(s);
	f(0, 0);
	pii curr = { 0,0 };
	while (curr.first != d) {
		pii nxt = ptr[curr.first][curr.second];
		string substr = a.substr(curr.first, nxt.first - curr.first);
		cout << substr;
		if (nxt.first != d)
			cout << "+";
		curr = nxt;
	}
	cout << "=" << s << endl;
	cin >> d;
}