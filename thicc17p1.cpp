#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

#define MAXN 100
#define MOD 1000000007

int costs[MAXN];

ll powmod(int a, int b) {
	ll x = 1;
	for (int i = 0; i < b; i++)
		x = x*a%MOD;
	return x;
}

int main() {
	int n, m; scan(n); scan(m);
	m = min(n, m);
	for (int i = 0; i < n; i++)
		scan(costs[i]);
	sort(costs, costs + n);
	int currplant = n - 1;
	int currround = 0;
	int currfriend = 0;
	ll total = 0;
	while (currplant >= 0) {
		total += powmod(costs[currplant], currround);
		currfriend++;
		if (currfriend == m)
		{
			currfriend = 0;
			currround++;
		}
		currplant--;
	}
	cout << total % MOD << endl;
}