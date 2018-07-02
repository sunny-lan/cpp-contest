
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	int k;
	cin >> k;
	if(k == 0) {
		printf("0\n");
		return 0;
	}
	if(k == 1) {
		printf("1\n");
		return 0;
	}
	if(k == 2) {
		printf("2\n");
		return 0;
	}
	ll fa = 1, fb = 1;
	ll sm = 2;
	for(int i = 3; i <= k; i++) {
		ll fc = fa + fb;
		sm += fc;
		fa = fb;
		fb = fc;
	}
	printf("%lld\n", sm);
}
