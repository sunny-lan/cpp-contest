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

string mp[25];
int fl, r, c;
bool v[25][25];
int f(int cr, int cc) {
	if (cr < 0 || cc < 0 || cr >= r || cc >= c)return 0;
	if (mp[cr][cc] == 'I')return 0;
	if (v[cr][cc])return 0;
	v[cr][cc] = true;
	return f(cr + 1, cc) + f(cr, cc + 1) + f(cr - 1, cc) + f(cr, cc - 1) + 1;
}

bool pred(int a, int b) { return a > b; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> fl >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> mp[i];
	vector<int> s;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			s.push_back(f(i, j));
	sort(s.begin(), s.end(), pred);
	int cnt = 0;
	for (int i : s)
		if (i > 0)
			if (i > fl)break;
			else
				cnt++, fl -= i;
	if(cnt==1)
		printf("%d room, %d square metre(s) left over\n", cnt, fl);
	else
	printf("%d rooms, %d square metre(s) left over\n", cnt, fl);
	cin >> fl;
}