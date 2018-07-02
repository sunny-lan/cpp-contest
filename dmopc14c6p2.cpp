#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	int n; scan(n);
	int mini ;
	int maxi ;
	scan(mini);
	scan(maxi);
	maxi = mini;
	int trainOther = 0;
	int sum = 0;
	for (int i = 1; i < n-1; i++) {
		int on, off; scan(on); scan(off);
		sum += off;
		int getoffNotBeg = min(off, trainOther);
		trainOther -= getoffNotBeg;
		maxi -= off-getoffNotBeg;
		trainOther += on;
	}
	printf("%d\n%d", max(mini - sum, 0), maxi);
	cin >> mini;
}