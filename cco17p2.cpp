#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

#define BITMASK (1ull<<30ull)-1ull

typedef unsigned long long ull;

inline ull c(int v) { return (ull)v; }

inline ull enc(int i, int j) { return c(i) << c(30) + c(j); }

inline int i(ull v) { return (int)(v >> c(30)); }

inline int j(ull v) { return (int)(v & BITMASK); }

unordered_map<ull, int> mini;
unordered_map<ull, int> maxi;

int fmin(int i, int j) {
	if (i > j)
		return fmin(j, i);

	if (i == 0)
		return 0;

	ull key = enc(i, j);
	if (mini.find(key) != mini.end())
		return mini[key];

	int res = INT_MAX;

	if (i == 2 * j)
		res = 1;
	else {
		int bs = 2 * j;
		if (i > bs) {
			int remainder = i%bs;
			int bc = i / bs;
			res = min(res, fmin(j, remainder) + bc);

			if (j % 2 == 0) {
				int rembs = j / 2;
				if (remainder < rembs) {
					remainder += bs;
					bc--;
				}
				int rembc = remainder / rembs;
				res = min(res, fmin(j, remainder%rembs) + rembc + bc);
			}
		}

		if (i < bs) {
			if (i % 2 == 0 && j >= i / 2)
				res = max(res, fmin(i - j / 2, j) + 1);
			else if (j % 2 == 0 && i >= j / 2)
				res = max(res, fmin(j - i / 2, i) + 1);
			else
				res = 1;
		}
	}

	mini[key] = res;
	return res;
}

int fmax(int i, int j) {
	if (i == 0 || j == 0)
		return 0;

	ull key = enc(i, j);
	if (maxi.find(key) != maxi.end())
		return maxi[key];

	int res = INT_MIN;
	if (i == 2 * j) {
		res = 1;
		if (j % 2 == 0)
			res = max(res, fmax(i - j / 2, j) + 1);
	}
	else {
		int bs = 2 * j;
		if (i > bs) {
			int remainder = i%bs;
			int bc = i / bs;
			res = max(res, fmax(j, remainder) + bc * 4);

			if (j % 2 == 0) {
				int rembs = j / 2;
				if (remainder < rembs) {
					remainder += bs;
					bc--;
				}
				int rembc = remainder / rembs;
				res = max(res, fmax(j, remainder%rembs) + rembc + bc * 4);
			}
		}

		if (i < bs) {
			if (i % 2 == 0 && j >= i / 2)
				res = max(res, fmax(i - j / 2, j) + 1);
			else if (j % 2 == 0 && i >= j / 2)
				res = max(res, fmax(j - i / 2, i) + 1);
			else
				res = 1;
		}
	}


	maxi[key] = res;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << fmin(n, m) << " " << fmax(m, n) << endl;
	cin >> n;
}