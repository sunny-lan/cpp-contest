#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

#define MAXN 100
#define MAXT 20010

int s[MAXN];
int dpa[MAXT], dpb[MAXT];
int cnt[MAXT];

int main(){
    memset(dpa, 0x3f, sizeof dpa);
    memset(dpb, 0x3f, sizeof dpb);
    dpa[0]=dpb[0]=0;
    int n,t;scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)scanf("%d", &s[i]);
    for(int i=0;i<n;i++)
    {
        memset(cnt, -1, sizeof cnt);
        int u;scanf("%d",&u);
        for(int k=0;k+s[i]<=t*2;k++)
        if(dpa[k]<INF){
            if(cnt[k]==-1)
                cnt[k]=u;
            if(cnt[k]>0){
                cnt[k+s[i]]=cnt[k]-1;
                dpa[k+s[i]]=min(dpa[k+s[i]], dpa[k]+1);
            }
        }
        for(int j=s[i];j<=t;j++)
            dpb[j]=min(dpb[j], dpb[j-s[i]]+1);
    }
//    for(int i=0;i<=t;i++)
//        printf("dpa %d: %d\n",i, dpa[i]);
//    printf("e");
//    for(int i=0;i<=t;i++)
//        printf("dpb %d: %d\n",i, dpb[i]);
//    printf("e");
//    if(dpa[t]>=0x3f3f3f3f)
//        dpa[t]=-1;
    int mini=INT_MAX;
    for(int i=t;i<=t*2;i++)
        mini=min(mini, dpa[i]+dpb[i-t]);
    if(mini>=INF)
        mini=-1;
    printf("%d\n", mini);
}
