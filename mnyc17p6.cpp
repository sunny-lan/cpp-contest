#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <unordered_set>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int f[MAXN];

int main() {
	int n, q; scan(n); scan(q);
	for (int i = 0; i < n; i++) {
		scan(f[i]);
	}

	for (int i = 0; i < q; i++) {
		int op, a, b; scan(op); scan(a); scan(b);
		
	}
}