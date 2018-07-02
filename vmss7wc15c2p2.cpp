#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	ws(cin);
	string test;
	getline(cin, test);
	int maxi = -1;
	int idx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; i - j >= 0 && i + j < n; j++) {
			if (test[i - j] != test[i + j])
				break;
			if (2 * j + 1 > maxi) {
				maxi = 2 * j + 1;
				idx = i - j;
			}
		}
		for (int j = 0; i - j-1 >= 0 && i + j < n; j++) {
			if (test[i - j-1] != test[i + j])
				break;
			if (2 * j + 2 > maxi) {
				maxi = 2 * j + 2;
				idx = i - j-1;
			}
		}
	}
	cout << test.substr(idx, maxi) << endl;
	cout << maxi << endl;
	cin >> n;
}