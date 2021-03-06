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
	int hi = 1000000,
		lo = 1;
	while (lo < hi) {
		int mid = (lo + (hi - lo)) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		char c = ' ';
		while (c != '<' && c != '>')
			c = getchar();
		if (c == '<')
			hi = mid - 1;
		else
			lo = mid;
	}
	printf("! %d\n", lo);
}