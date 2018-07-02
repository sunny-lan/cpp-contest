#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int f[MAXN];
vector<int> p[MAXN];

int cnt(int x, int l, int r) {
	return upper_bound(p[x].begin(), p[x].end(), r) - lower_bound(p[x].begin(), p[x].end(), l);
}

int main() {
	srand(time(0));
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &f[i]);
		f[i]--;
		p[f[i]].push_back(i);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		int fnum = -1;
		for(int tr = 0; tr < 36; tr++) {
			int sel;
			do {
				sel = f[rand() % (r - l + 1) + l];
			} while(sel == fnum);
			int cn = cnt(sel, l, r);
			if(cn * 3 >= r - l + 1)
				if(fnum == -1) {
					if(cn * 3 >= (r - l + 1) * 2)
					{
						printf("YES\n");
						goto outer;
					}else fnum=sel;
				} else {
                    printf("YES\n");
						goto outer;
				}
		}
		printf("NO\n");
	outer:
		continue;
	}
}
