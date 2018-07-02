#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

	int n;
int x[MAXN], y[MAXN];
int xx[MAXN], yy[MAXN];

int dd(int x, int y){
    int res=0;
    for(int i=0;i<n;i++)
            res+=abs(xx[i]-x)+abs(yy[i]-y);
    return res;
}

unordered_map<int, bool> sdf[20004];
unordered_map<int,bool>*fds=sdf+10002;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]), xx[i]=x[i], yy[i]=y[i], fds[x[i]][y[i]]=true;
	sort(x, x + n);
	sort(y, y + n);
	int xlo, xhi, ylo, yhi;
	if(n % 2)
		xlo = xhi = x[n / 2], ylo = yhi = y[n / 2];
	else
		xlo = x[n / 2 - 1], xhi = x[n / 2],
		ylo = y[n / 2 - 1], yhi = y[n / 2];
    int ct=(xhi-xlo+1)*(yhi-ylo+1), dst=0;
    for(int i=0;i<n;i++){
        if(xx[i]>=xlo && xx[i]<=xhi && yy[i]>=ylo && yy[i]<=yhi)
        ct--;
        dst+=abs(xx[i]-xlo)+abs(yy[i]-ylo);
    }
    if(ct==0){
            int mini=INT_MAX, cnt=0;
        for(int a=x[0];a<=x[n-1];a++)
            for(int b=y[0];b<=y[n-1];b++)
            if(!fds[a][b]){
                    int alt=dd(a,b);
                if(alt<mini)
                mini=alt, cnt=0;
            if(mini==alt)
                cnt++;
            }
            ct=cnt,dst=mini;
    }
    printf("%d %d\n", dst, ct);
}
