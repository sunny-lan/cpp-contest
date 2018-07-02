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

#define S 0
#define I 1
#define L 2
#define H 3

int state[10];

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		char op1; int x1; scanf(" %c %d", &op1, &x1);
		for (int j = 0; j < 10; j++) {
			if (op1 == '&')
			{
				if (!((x1 >> j) & 1))
					state[j] = L;
			}
			else if (op1 == '^')
			{
				if ((x1 >> j) & 1)
					state[j] ^= 1;
			}
			else
			{
				if ((x1 >> j) & 1)
					state[j] = H;
			}
		}
	}
	int xor = 0, or = 0, and = 1023;
	for (int i = 0; i < 10; i++) {
		if (state[i] == H)
			or ^= 1 << i;
		else if (state[i] == L)
			and ^= 1 << i;
		else if (state[i] == I)
			xor ^= 1 << i;
	}
	printf("3\n^ %d\n| %d\n& %d\n", xor, or , and);
	cin >> n;
}