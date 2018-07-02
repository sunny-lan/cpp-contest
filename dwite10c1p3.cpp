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
	int n, m;
	for (int t = 0; t < 5; t++) {
		scan(n); scan(m);
		int cnt = 0;
		for (int i = 0; i < 30; i++)
			if ((n >> i) & 1)
			{
				int cust = m >> i;
				int left = m - (cust << i);
				cnt += cust;
				int mult = 1;
				while (left > 0) {
					if (left & 1)
						cnt += (1 << i) / mult;
					mult <<= 1;
					left >>= 1;
				}
						
			}
		printf("%d\n", cnt);
	}
	cin >> m;
}