
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int r, c;
		cin >> r >> c;
		if(r == 1 || c == 1)
			cout << max(r, c) - 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
