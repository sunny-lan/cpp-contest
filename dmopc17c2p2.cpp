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
#include <stack>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int main() {
	string s; cin >> s;
	int n = s.length();
	stack<char> cust;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == ')') {
			if (!cust.empty() && cust.top() == '(') {
				cust.pop();
				continue;
			}
		}
		cust.push(c);
	}
	if (cust.empty()) {
		printf("YES\n");
		return 0;
	}
	if (cust.size() == 2) {
		char c1 = cust.top(); cust.pop();
		char c2 = cust.top(); cust.pop();
		if (c1 == c2)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}