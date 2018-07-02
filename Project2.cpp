#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int main() {
	string num; cin >> num;
	int len = num.length();
	if (len < 15) {
		ll fac = 1;
		ll k = stoll(num);
		for (int i = 1; i < 20; i++) {
			fac *= i;
			if (fac == k)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	else {
		double tot=0;
		for (int i = 2;; i++) {
			tot += log10(i);
			if(ceil(tot)==len)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
}