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

#define MAXL 50
#define MAXN MAXL*10
int tree[MAXN];

string in;
int x;

void proc(int l, int r, int idx = 1) {
	if (in[l] == ' ')
		return proc(l + 1, r);
	if (in[r - 1] == ' ')
		return proc(l, r - 1);
	if (in[l] == '(')
	{
		int mid = l + 1;
		while (in[mid] == ' ')mid++;
		int bc = 0;
		while (in[mid] != ' ' || bc>0) {
			if (in[mid] == '(')bc++;
			if (in[mid] == ')')bc--;
			mid++; 
		}
		tree[idx] = 0;
		proc(l + 1, mid, idx * 2); proc(mid + 1, r - 1, idx * 2 + 1);
	}
	else {
		tree[idx] = stoi(in.substr(l, r - l));
	}
}

#define MAXX 2600

int dp[MAXN][MAXX];

int tmp[2][MAXX];

void f(int i = 1) {
	if (tree[i] == 0) {
		f(i * 2);
		f(i * 2 + 1);
		memset(tmp, 0, sizeof tmp);
		for (int j = 0; j <= x; j++)
			for (int w = 0; w <= j; w++)
				for (int d = 0; d < 2; d++)
					tmp[d][j] = max(tmp[d][j], min((1 + w)*(1 + w), dp[i * 2 + d][j - w]));
		for (int j = 0; j <= x; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] = max(dp[i][j], tmp[0][k] + tmp[1][j - k]);
	}
	else {
		for (int s = 0; s <= x; s++)
			dp[i][s] = tree[i] + s;
	}
}

void find_and_replace(string& source, string const& find, string const& replace)
{
	for (string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, in);
	cin >> x;
	find_and_replace(in, "( ", "(");
	find_and_replace(in, " )", ")");
	proc(0, in.length());
	f();
	printf("%d\n", dp[1][x]);
	cin >> x;
}