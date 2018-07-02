#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 200000

// gotta love codeforces

int n;  // array size
int t[2 * MAXN];

void inc(int p, int value) {  // set value at position p
	for (t[p += n] += value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int sum(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

struct query {
	int a;
	int b;
	int idx;
};

bool operator <(const query& x, const query& y) {
	return false;
}

vector<pair<int, int>> trees;
vector<pair<int, query>> queries;

int ans[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		trees.push_back(make_pair(m, i));
	}
	sort(trees.begin(), trees.end());
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, q;
		cin >> a >> b >> q;
		query m = {
			a, b, i
		};
		queries.push_back(make_pair(q, m));
	}

	sort(queries.begin(), queries.end());

	int mpend = trees.size() - 1;
	for (int i = q - 1; i >= 0; i--) {
		int q = queries[i].first;
		query curr = queries[i].second;

		//cout << "query: q=" << q << " a=" << curr.a << " b=" << curr.b << endl;

		while (mpend >= 0 && trees[mpend].first >= q) {
			inc(trees[mpend].second, trees[mpend].first);
			mpend--;
		}

		//for (int i = 0; i < n; i++)
			//cout << sum(i, i + 1) << " ";

		//cout << endl;

		ans[curr.idx] = sum(curr.a, curr.b + 1);
	}

	for (int i = 0; i < q; i++) cout << ans[i] << endl;
	cin >> n;
}