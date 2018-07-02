#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	ll hi = 2000000001, lo = 1;
	while (lo < hi) {
		ll mid = (hi + lo) / 2;
		cout << mid << endl;
		string res; cin >> res;
		if (res == "FLOATS")
			hi = mid;
		else if (res == "SINKS")
			lo = mid + 1;
		else
			break;
	}
}