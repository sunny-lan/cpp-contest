#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int s[MAXN];
int p[MAXN];
int ptr[MAXN];

bool pred(int a, int b) {
	if (s[a] == s[b])
		return p[a] > p[b];
	if (p[a] == p[b])
		return s[a] < s[b];

}

int main() {
	int n, m; scan(n); scan(m);
	for (int i = 0; i < n; i++) {
		scan(s[i]); scan(p[i]);
		ptr[i] = i;
	}
	sort(ptr, ptr + n, pred);
	int mass = 0;
	int val = 0;
	for (int i = 0; i < n; i++)  if (mass + s[ptr[i]] <= m) {
		val += p[ptr[i]];
		mass += s[ptr[i]];
	}
	cout << val << endl;
}