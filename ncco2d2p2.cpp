#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

#define MAXN 100010

unordered_map<ll, int> edj;
int cidx = 0;
int n;
int p[MAXN], sz[MAXN], ans[MAXN];
int f(int x) {
	if(p[x] == x)
		return x;
	return p[x] = f(p[x]);
}
unordered_set<int> col[MAXN];

void mrg(int x, int y) {
	int px = f(x), py = f(y);
	if(px == py)
		return;
	if(sz[px] > sz[py])
		swap(px, py);
	bool res = true;
	for(int i : col[px]) {
		if(res == 1)
			if(col[py].count(i) > 0)
				res = false;
		col[py].insert(i);
	}
	sz[py] += sz[px];
	sz[px] = 0;
	p[px] = py;
	if(res){
        ans[py]=ans[py]+ans[px]+1;
	}else ans[py]=0;
}

void add(int x, int y) {
	if(x > y)
		swap(x, y);
	if(edj.count(x * n + y) == 0) {
		edj[x * n + y] = cidx;
		return;
	}
	 mrg(edj[x * n + y], cidx);
}

int main() {
//	memset(fst, -1, sizeof fst);
//    freopen("C:\\Users\\sunny\\Desktop\\data.txt","r",stdin);
	scanf("%d", &n);
	for(int i = 0; i < n - 2; i++) {
		int a, b, c, d;
		p[i] = i, sz[i] = 1;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		col[i].insert(d);
		a--, b--, c--;
		add(a, b);
		add(b, c);
		add(c, a);
		cidx++;
	}
    printf("%d\n", ans[f(0)]);

}
