#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAXN 100000

typedef long long ull;

vector<ull> t;

void erase(ull value)
{
	auto pr = lower_bound(begin(t), end(t), value);
	t.erase(pr);
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	ull w;
	cin >> n >> w;
	for (int i = 0; i < n; ++i)
	{
		ull v;
		cin >> v;
		t.push_back(v);
	}

	t.push_back(w);

	sort(t.begin(), t.end());

	ull mini = 0ll;
	for (int i = 1; i <= n; ++i)
		mini += t[i] - t[i - 1];

	erase(w);

	ull maxi = 0ll;
	bool high = true;
	int hi = n - 1;
	int lo = 0;
	ull curr = w;
	while (lo <= hi) {
		int next = high ? hi : lo;
		ull a = abs(w - t[next]);
		ull b = abs(curr - t[next]);
		maxi += max(a, b);
		curr = t[next];
		if (high) --hi; else ++lo;
		high = !high;
	}

	ull maxi2 = 0ll;
	high = false;
	hi = n - 1;
	lo = 0;
	curr = w;
	while (lo <= hi) {
		int next = high ? hi : lo;
		ull a = abs(w - t[next]);
		ull b = abs(curr - t[next]);
		maxi2 += max(a, b);
		curr = t[next];
		if (high) --hi; else ++lo;
		high = !high;
	}


	cout << mini << " " << max(maxi, maxi2) << endl;
	cin >> n;
}