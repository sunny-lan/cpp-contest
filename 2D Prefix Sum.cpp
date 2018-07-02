#include <iostream>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//template variables
#define MAXN 51
int n, m;
int value[MAXN][MAXN];

//template starts here
int prefix[MAXN+1][MAXN+1];

//GUD CONTENT:
//sum for rectangle prism in any dimension
//let (a1,a2,...,an) be the first point
//let (b1,b2,...,bn) be the second point (should have larger coordinates)
//answer should be sum of psa(...) for all combinations of a and b for each dimension
//each term of sum can either have positive sign or negative sign.
//if it has odd number of dimesions in b, sign is negative
//if it has even number, sign is positive

inline int sum(int x, int y, int x2, int y2) {
	int whole = prefix[y2][x2];
	int lcol = prefix[y][x2];
	int minsqr = prefix[y][x];
	int ucol = prefix[y2][x];
	return whole - ((lcol + ucol) - minsqr);
}

void construct() {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			prefix[i][j] = prefix[i - 1][j] + value[i - 1][j - 1];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			prefix[i][j] += prefix[i][j - 1];
}
//template ends here

int main() {
	scan(n); scan(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scan(value[i][j]);

	construct();

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			cout << prefix[i][j] << " ";
		cout << endl;
	}

	int q;
	scan(q);
	for (int i = 0; i < q; i++) {
		int x, y, x2, y2;
		scan(x); scan(y); scan(x2); scan(y2);
		cout << sum(x, y, x2, y2) << endl;
	}
}