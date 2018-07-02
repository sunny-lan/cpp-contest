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

#define MAXN 20

int s[MAXN];


vector<pair<int, pair<vector<int>, vector<int>>>> pos;

int endPt = 0;

vector<int> ca;
vector<int> cb;

void f(int i, int sa, int sb) {
	if (i == endPt) {
		vector<int> cop = ca;
		vector<int> copb = cb;
		pos.push_back({ sa - sb , {cop, copb} });
		return;
	}
	ca.push_back(i);
	f(i + 1, sa + s[i], sb);
	ca.pop_back();

	cb.push_back(i);
	f(i + 1, sa, sb + s[i]);
	cb.pop_back();

	f(i + 1, sa, sb);
}

bool pred(pair<int, pair<vector<int>, vector<int>>> a, pair<int, pair<vector<int>, vector<int>>> b) {
	return a.first < b.first;
}

bool pred2(pair<int, pair<vector<int>, vector<int>>> a, pair<int, pair<vector<int>, vector<int>>> b) {
	return -a.first < -b.first;
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++)
		scan(s[i]);

	endPt = n / 2;
	f(0, 0, 0);
	vector<pair<int, pair<vector<int>, vector<int>>>> pos2 = pos;
	pos = vector<pair<int, pair<vector<int>, vector<int>>>>();

	int tmp = endPt;
	endPt = n;
	f(tmp, 0, 0);
	sort(pos2.begin(), pos2.end(), pred);
	sort(pos.begin(), pos.end(), pred2);

	int mini = INT_MAX;
	pair<vector<int>, vector<int>> ba, bb;
	int b = 0;
	for (auto cust : pos2) {
		while (b < pos.size() && cust.first + pos[b].first > 0)
			b++;
		if (b >= pos.size())break;
		if (abs(cust.first + pos[b].first) < mini)
		{
			pair<vector<int>, vector<int>>ta = cust.second, tb = pos[b].second;
			if (ta.first.size() + tb.first.size() != 0 && ta.second.size() + tb.second.size() != 0) {
				mini = abs(cust.first + pos[b].first);
				ba = ta, bb = tb;
			}
		}
		if (b > 0)
			if (abs(cust.first + pos[b - 1].first) < mini) {
				pair<vector<int>, vector<int>>ta = cust.second, tb = pos[b - 1].second;
				if (ta.first.size() + tb.first.size() != 0 && ta.second.size() + tb.second.size() != 0) {
					mini = abs(cust.first + pos[b - 1].first);
					ba = cust.second, bb = pos[b - 1].second;
				}
			}
	}

	for (int i : ba.first)
		printf("%d ", i + 1);
	for (int i : bb.first)
		printf("%d ", i + 1);
	printf("\n");
	for (int i : ba.second)
		printf("%d ", i + 1);
	for (int i : bb.second)
		printf("%d ", i + 1);
	printf("\n");
}