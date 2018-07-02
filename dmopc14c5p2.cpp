#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	int n; scan(n);
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		int a, b; scan(a); scan(b);
		maxi = max(maxi, b - a);
	}
	cout << maxi << endl;
}