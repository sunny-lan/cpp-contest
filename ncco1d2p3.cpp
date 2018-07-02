#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define MAXN 1000000
int *a;
int *ptr;
bool pred(int x, int y){
    return max(a[x],a[x+1])<max(a[y], a[y+1]);
}

int *p;
int f(int x){
    if(p[x]==x)
        return x;
    return p[x]=f(p[x]);
}

int main() {
	int n;
	scanf("%d", &n);
	p=new int[n];
	ptr=new int[n-1];
	a=new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if(i<n-1)
		ptr[i]=i;
		p[i]=i;
	}
	sort(ptr, ptr+n-1, pred);
    ll cst=0;
    for(int i=0;i<n-1;i++){
        int px=ptr[i], py=ptr[i]+1;
        if(px==py)continue;
        p[px]=py;
        cst+=(a[py]=max(a[py], a[px]));
    }
    printf("%lld\n", cst);
}
