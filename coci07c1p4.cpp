#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MOD 100000
#define MAXN 200

string v;

int dp[MAXN][MAXN];

bool open(int i) {
	return v[i] == '{' || v[i] == '[' || v[i] == '(' || v[i] == '?';
}

bool close(int i) {
	return v[i] == '}' || v[i] == ']' || v[i] == ')' || v[i] == '?';
}

char inv(char i) {
	switch (i) {
	case '{':
		return '}';
	case '[':
		return ']';
	case '(':
		return ')';
	case '}':
		return '{';
	case ']':
		return '[';
	case ')':
		return '(';
	}
}

bool cmp(int i, int j) {
	if (v[i] == '?')
		return true;
	if (v[j] == '?')
		return true;
	return inv(v[j]) == v[i];
}

string indent = "";

int fCust(int i, int j);

int f(int i, int j) {
	if (i > j)
		return 1;
	if ((j - i + 1) % 2 == 1)
		return 0;


	indent += "    ";

	cout << indent << "check [" << i << "=" << v[i] << "," << j << "=" << v[j] << "] -> " << v.substr(i, j - i + 1) << endl;

	if (dp[i][j] != -1)
	{
		cout << indent << " already computed, ret=" << dp[i][j] << endl;
		indent = indent.substr(4);
		return dp[i][j];
	}
	int ret = 0;
	if (open(i) && close(j)) {
		cout << indent << " is closed" << endl;
		if (cmp(i, j)) {
			int  ret1 = 0;
			cout << indent << " is equal" << endl;
			if (v[i] == '?' && v[j] == '?') {
				cout << indent << "  special" << endl;
				ret1 = 3 * f(i + 1, j - 1);
			}
			else
				ret1 = f(i + 1, j - 1);
			cout << indent << " ret1=" << ret1 << endl;
			ret += ret1;
		}
		int ret2 = 0;
		for (int k = i + 1; k < j; k++) {
			cout << indent << " checking k=" << k << endl;
			ret2 = max(ret2, f(i, k)*f(k + 1, j));
		}
		cout << indent << " ret2=" << ret2 << endl;
		ret += ret2;
	}
	ret %= MOD;
	cout << indent << " ret=" << ret << endl;
	indent = indent.substr(4);
	dp[i][j] = ret;
	return ret;
}

int fCust(int i, int j) {

}

int main() {
	int n;
	cin >> n;
	//cout << n << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	ws(cin);
	getline(cin, v);
	//cout << v << endl;
	cout << f(0, n - 1) << endl;
	cin >> n;
}