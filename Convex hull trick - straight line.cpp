#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

struct line {
	double b, m;
	double l, r;
};

bool pred1(line a, line b) {
	return a.m > b.m;
}

bool pred2(line a, double b) {
	return a.r < b;
}

double intersection(line a, line b) {
	return (b.b - a.b) / (a.m - b.m);
}

vector<line> preproc(vector<line> lines) {
	sort(lines.begin(), lines.end(), pred1);
	vector<line> res;
	lines[0].l = -INFINITY;
	res.push_back(lines[0]);
	for (int i = 1; i < lines.size(); i++) {
		line& c = lines[i];
		while (true) {
			auto l = res.rbegin();
			double x = intersection(*l, c);
			if (l->l < x) {
				l->r = c.l = x;
				break;
			}
			res.pop_back();
		}
		res.push_back(c);
	}
	res[res.size() - 1].r = INFINITY;
	return res;
}

int findRange(double x, vector<line> lines) {
	int hi = lines.size(),
		lo = 0;
	while (lo < hi) {
		int mid = (hi + lo) / 2;
		if (lines[mid].r < x)
			lo = mid+1;
		else if (lines[mid].l > x)
			hi = mid;
		else return mid;
	}
	return -1;
}

double f(double x, vector<line> lines) {
	line l =lines[findRange(x, lines)];
	return l.b + x*l.m;
}


int main() {
	int n; cin >> n;
	vector<line> lines;
	for (int i = 0; i < n; i++) {
		line curr;
		cin >> curr.b >> curr.m;
		lines.push_back(curr);
	}

	lines = preproc(lines);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		double x; cin >> x;
		cout << f(x, lines) << endl;
	}
}