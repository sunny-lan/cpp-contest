#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int n, a[MAXN][MAXN];

int wa()
{
    int x=1,y=1,sx=0,sy=0;
    for(int i=2; i<=n; i++)
    {
        if(sx+a[x][i]<sy+a[y][i])
            sx+=a[x][i], x=i;
        else
            sy+=a[y][i], y=i;
    }
    return sx+sy;
}

int dp[MAXN][MAXN];
int f(int x, int y)
{
    int lv=max(x,y)+1;
    if(lv==n+1)
        return 0;
    int &res=dp[x][y];
    if(res!=-1)
        return res;
    res=min(f(lv, y)+a[x][lv], f(x, lv)+a[y][lv]);
    return res;
}

int ac()
{
    memset(dp, -1, sizeof dp);
    return f(1,1);
}

double score()
{
    return wa()/(4.0*ac());
}

double maxi=0;
int b[MAXN][MAXN];

int rng(int lo, int hi)
{
    return rand()%(hi-lo)+lo;
}

double rng()
{
    return rand()/(double)RAND_MAX;
}
void anneal()
{
    n=27;
    for(int src=1; src<n; src++)
        for(int dst=src+1; dst<=n; dst++)
            a[src][dst]=rng(0, 2)*99+1;

    double cur=0;
    int kst=0;
    for(double temp=0.5; temp>0.1; temp-=0.0000003,kst++)
    {
        int src,dst,idx=rng(0, n*(n-1)/2), cnt=0;
        int old;
        for( src=1; src<n; src++)
            for( dst=src+1; dst<=n; dst++)
            {
                if(idx==cnt)
                    goto outer;
                cnt++;
            }
outer:
        old=a[src][dst];
        a[src][dst]=old==1?100:1;
        double alt=score();
        if(kst%50000==0){
            printf("temp=%lf\n", temp);
            kst=0;
        }
        if(alt>maxi)
        {
            printf("max=%lf\n", alt);
            maxi=alt;
            memcpy(b,a,sizeof a);
        }
        if(alt>cur)
        {
            cur=alt;
            continue;
        }
        double fnc=exp( (alt-cur)/temp);
        if(rng()<fnc)
            cur=alt;
        else
            a[src][dst]=old;
    }
    printf("score: %lf\n", maxi);
    printf("%d\n", n);
    for(int src=1; src<n; src++)
    {
        for(int dst=src+1; dst<=n; dst++)
            printf("%d ", b[src][dst]);
        printf("\n");
    }
}

int main()
{
    srand(time(0));
//cin>>n;
//for(int src=1; src<n; src++)
//        for(int dst=src+1; dst<=n; dst++)
//            cin >>a[src][dst];
    anneal();
//        printf("%d %d\n", ac(), wa());
}
