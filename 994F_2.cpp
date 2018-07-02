#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 51

int n;
pii task[MAXN];

double dp[MAXN][MAXN][MAXN];
double mid;

double g(int cur, int pick, int sm){
    if(pick<0)return INFINITY;
    if(cur==n)
        return 0;
    double &res=dp[cur][pick][sm];
    if(res!=-INFINITY)
        return res;
    if(cur>0 && task[cur-1].f>task[cur].f)
        pick+=sm, sm=0;
    res=min(g(cur+1,pick, sm+1)+(task[cur].f-mid*task[cur].s), g(cur+1, pick-1, sm));
    return res;
}

double f(){
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
            dp[i][j][k]=-INFINITY;
    return g(0,0,0);
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)scanf("%d", &task[i].f);
    for(int i=0;i<n;i++)scanf("%d", &task[i].s);
    sort(task, task+n);
    reverse(task, task+n);

    //for(mid=8;mid<=9;mid+=0.01){
      //  printf("f(%lf)=%lf\n", mid, f());
    //}

    double hi=1e8, lo=0;
    for(int i=0;i<100;i++){
        mid=(hi+lo)/2;
        //printf("f(%lf)=%lf\n", mid, f());
        if(f()<=0)
            hi=mid;
        else
            lo=mid;
    }

    printf("%.0lf\n", ceil(lo*1000));
}
