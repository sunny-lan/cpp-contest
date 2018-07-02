#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef string* strptr;
#define MAXN 2001
#define MAXM 5001

int dat[MAXN];
strptr monsters[MAXN];

int n, m;

int tree[MAXN * 2];
int treeN;

void construct() {
	for (int i = 0; i < treeN; i++)
		tree[i + treeN] = dat[i];
	for (int i = treeN - 1; i > 0; i--)
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
}

void update(int p, int val) {
	for (tree[p += treeN] = val; p > 1; p >>= 1)
		tree[p >> 1] = min(tree[p], tree[p ^ 1]);
}

int query(int l, int r) {
	int res = MAXM+1;
	for (l += treeN, r += treeN; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = min(res, tree[l++]);
		if (r & 1)
			res = min(res, tree[--r]);
	}
	return res;
}

int calcCommon(int i, int k, int s) {
	for (int j = s; j < m; j++) {
		if ((*monsters[i])[j] != (*monsters[k])[j]) {
			return j;
		}
	}
	return m;
}

int main()
{
	cin >> n >> m;
	treeN = 0;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		monsters[i] = new string(tmp);
		if (i > 0) {
			treeN++;
			dat[i - 1] = calcCommon(i - 1, i, 0);
		}
	}
	construct();

	/*for (int i = 0; i < n - 1; i++)
	{
		cout << query(i, i + 1) << endl;
	}*/

	int q;
	cin >> q;
	//cout << "monsters[" << 0 << "]=" << *monsters[0] << endl;
	for (int qu = 0; qu < q; qu++) {
		int i, j;
		cin >> i >> j;
		i--;
		j--;

		//cout << "monsters[" << i << "]=" << *monsters[i] << endl
		if (i == j)
			cout << m << endl;
		else {
			int qres = query(i, j);
			cout << (j - i + 1)*qres << endl;

			string* tmp = monsters[i];
			//cout <<"monsters["<<i<<"]="<< *(monsters[i]) << endl;
			monsters[i] = monsters[j];
			monsters[j] = tmp;

			if (i < n - 1)
				update(i, calcCommon(i, i + 1, qres));
			if (i > 0)
				update(i - 1, calcCommon(i - 1, i, 0));

			if (j < n - 1)
				update(j, calcCommon(j, j + 1, 0));
			if (j > 0)
				update(j - 1, calcCommon(j - 1, j, qres));
		}
	}
	return 0;
}