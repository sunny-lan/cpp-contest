#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <set>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

multiset<int> elems;

int main() {
	int n; scan(n);
	elems.insert(0);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int r; scan(r);
		if (!flag)continue;
		auto ptr = elems.lower_bound(r);
		if (ptr == elems.begin()) {
			flag = false;
			continue;
		}
		ptr--;
		elems.erase(ptr);
		elems.insert(r);
		elems.insert(r);
	}
	if (flag)cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}