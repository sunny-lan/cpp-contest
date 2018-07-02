#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int xx[4], yy[4];

int main(){
    int minx=101, miny=101, maxx=-101, maxy=-101;
    for(int i=0;i<4;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        minx=min(minx, x);
        maxx=max(maxx, x);
        miny=min(miny, y);
        maxy=max(maxy, y);

        xx[i]=x, yy[i]=y;
    }

    int ty=-101, tx,by=101;
    int minx2=101, miny2=101, maxx2=-101, maxy2=-101;
    for(int i=0;i<4;i++)
    {
        int x,y;scanf("%d%d", &x, &y);
        if(y>ty)
            ty=y, tx=x;
        if(y<by)
            by=y;

        if(x>=minx && x<=maxx && y>=miny && y<=maxy)
        {
            printf("yes\n");
            return 0;
        }
        minx2=min(minx2, x);
        maxx2=max(maxx2, x);
        miny2=min(miny2, y);
        maxy2=max(maxy2, y);
    }

    double ccx=(minx+maxx)/2.0, ccy=(miny+maxy)/2.0;

    double cy=(ty+by)/2.0, r=abs(cy-ty);
    if(abs(ccx-tx)+abs(ccy-cy)<=r)
    {
        printf("yes\n");
        return 0;
    }
    //cout << tx<< ", "<<cy<<" r="<<r<<endl;
    for(int i=0;i<4;i++){
        if(abs(xx[i]-tx)+abs(yy[i]-cy)<=r)
        {
            printf("yes\n");
            return 0;
        }
    }

        printf("no\n");
}
