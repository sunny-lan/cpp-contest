#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 20
#define CUST 1<<MAXN

int n, m;
int t[CUST << 1];
int wins[CUST];
int skill[CUST];

void construct() {
	for (int i = n - 1; i > 0; i--)
		if (skill[t[i << 1]] > skill[t[i << 1 | 1]])
			t[i] = t[i << 1], wins[t[i]]++;
		else
			t[i] = t[i << 1 | 1], wins[t[i]]++;
}

void update(int p, int v) {
	skill[p] = v;
	wins[p] = 0;
	int h = 0;
	for (p += n; p > 0; p >>= 1, h++) {
		if (skill[t[p]] > skill[t[p ^ 1]])
			t[p >> 1] = t[p], wins[t[p^1]]=h;
		else
			t[p >> 1] = t[p ^ 1], wins[t[p]]=h;
		if(p!=1)
		wins[t[p >> 1]] = h + 1;
	}
}

int main() {
	scan(n); scan(m);
	n = 1 << n;
	for (int i = 0; i < n; i++) {
		scan(skill[i]);
		t[i + n] = i;
	}
	construct();
	for (int i = 0; i < m; i++)
	{
		char op; scanf(" %c", &op);
		if (op == 'R')
		{
			int j, s; scan(j); scan(s);
			update(--j,s);
		}
		else if (op == 'W')
			printf("%d\n", t[1] + 1);
		else {
			int j; scan(j);
			printf("%d\n", wins[--j]);
		}
	}
	cin >> n;
}