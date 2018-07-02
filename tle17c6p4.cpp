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
typedef long long ll;

int main()
{
	int n;
	scanf("%d", &n);
	unordered_map<int, vector<pair<int, int>>> vert;
	unordered_map<int, vector<pair<int, int>>> hor;
	unordered_map<int, unordered_map<int, bool>> pts;
	unordered_map<int, unordered_map<int, bool>> pts1;
	for (int i = 0; i<n; i++)
	{
		int p, q, r, s;
		scanf("%d %d %d %d", &p, &q, &r, &s);
		vert[p].push_back({ q, 0 });
		vert[p].push_back({ s, 1 });
		vert[r].push_back({ q, 0 });
		vert[r].push_back({ s, 1 });
		hor[q].push_back({ p, 0 });
		hor[q].push_back({ r, 1 });
		hor[s].push_back({ p, 0 });
		hor[s].push_back({ r, 1 });
		pts[p][q] = false;
		pts[r][s] = false;
		pts[p][s] = false;
		pts[r][q] = false;
		pts1[p][q] = false;
		pts1[r][s] = false;
		pts1[p][s] = false;
		pts1[r][q] = false;
	}

	for (auto v : vert) {
		auto &ptsz = v.second;
		sort(ptsz.begin(), ptsz.end());
		int cnt = 0;
		for (auto p : ptsz) {
			if (p.second == 0) {
				if (cnt==0)pts[v.first][p.first] = true;
				cnt++;
			}
			else {
				cnt--;
				if (cnt==0)pts[v.first][p.first] = true;
			}
		}
	}

	for (auto v : hor) {
		auto &ptsz = v.second;
		sort(ptsz.begin(), ptsz.end());
		int cnt = 0;
		for (auto p : ptsz) {
			if (p.second == 0) {
				if (cnt==0)pts1[p.first][v.first] = true;
				cnt++;
			}
			else {
				cnt--;
				if (cnt==0)pts1[p.first][v.first] = true;
			}
		}
	}

	int res = 0;
	for (auto mp : pts) {
		for (auto v : mp.second) {
			if (v.second && pts1[mp.first][v.first])
				res++;
		}
	}

	printf("%d", res);
	cin >> res;
}
