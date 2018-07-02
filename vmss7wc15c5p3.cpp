#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

//template parameters
#define MAXN 5000
#define NUM ll

ll actual[MAXN][MAXN];

//template begin
NUM* bit;

void update(int p, NUM v) {
	for (int x = p; x <= MAXN; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

NUM query(int p) {
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main() {
	int n; scan(n);
	ll total = 0;
	for (int i = 0; i < n; i++) {
		int op, r, c; ll v; scan(op); scan(r); scan(c); scan(v);
		int diagonal = min(MAXN, r + c);
		int startIdx = diagonal - r;
		bit = actual[diagonal];
		if (op == 1) {
			update(startIdx, v);
		}
		else {
			total+= (query(startIdx+v) - query(startIdx - 1)) % 1000000007;
		}
	}
	cout << total % 1000000007 << endl;
}