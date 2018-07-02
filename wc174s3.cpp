#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
#define MAXN 1001

int c[MAXN][MAXN];


int main() {
	ll tot = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
outer:
	for(int i = 0; i < n; i++) {
		int mc = -1, mr = -1;
		for(int j = 0; j < n; j++)
			mc = max(mc, c[i][j]), mr = max(mr, c[j][i]);
		if(mc == mr)
			continue;
		else {
			int kst = min(mc, mr);
			for(int j = 0; j < n; j++) {
				if(c[i][j] > kst)
					tot += c[i][j] - kst, c[i][j] = kst;
				if(c[j][i] > kst)
					tot += c[j][i] - kst, c[j][i] = kst;
			}
			goto outer;
		}

	}

    printf("%lld\n", tot);
}
