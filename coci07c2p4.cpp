#include <iostream>
#include <cmath>

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100010

int bit[MAXN];
int n;
int loc[MAXN];
int init = 0;

void update(int p, int v) {
	if (p > n)return;
	if (p == 0) { init += v; return; }
	int curr = p;
	while (curr <= MAXN) {
		bit[curr] += v;
		curr += curr & -curr;
	}
}

int query(int p) {
	int res = init;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

int main() {
	scan(n);
	for (int i = 1; i <= n; i++) {
		int v;
		scan(v);
		loc[v] = i;
	}

	bool phase = false;
	int l = 1;
	int r = n;
	while (l <= r) {
		if (phase) {
			int rem = loc[r];
			rem += query(rem);
			cout << abs(r - rem) << endl;
			update(loc[r], -1);
			r--;
		}
		else {
			int rem = loc[l];
			rem += query(rem);
			cout << abs(l - rem) << endl;
			update(0, 1);
			update(loc[l], -1);
			l++;
		}
		phase = !phase;
	}
	cin >> n;
}