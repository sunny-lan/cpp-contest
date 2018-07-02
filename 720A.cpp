#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

#define MAXK 10000

int l[MAXK];
int r[MAXK];

int n, m, k;
bool **v;
int cnt=0;
void st(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m)
        return;
    if(v[x][y])return;
    cnt++;
    v[x][y]=true;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	v = new bool*[n];
	for(int i = 0; i < n; i++)
		v[i] = new bool[i];
	for(int i = 0; i < k; i++)
		scanf("%d", &l[i]);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
		scanf("%d", &r[i]);
	sort(l, l + k), sort(r, r + q);
	int a = 0, b = 0;
	for(int i = 0; i < n + m; i++) {
		while(a < k && l[a] <= i)
			a++;
		while(b < q && r[b] <= i)
			b++;

	}
}
