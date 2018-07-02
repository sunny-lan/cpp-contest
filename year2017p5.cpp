#include <iostream>

using namespace std;

typedef long long ll;

#define MAXN 100005

int v[MAXN];
int n,k;
int cnt[MAXN];
ll psa[MAXN];

ll frg(int st, int ed){
    int lo=0, hi=n+1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        int l=max(0,st-mid),r=min(n, ed+mid);
        int v=cnt[r]-cnt[r];
        if(v>=st-ed)
            hi=mid;
        else
        lo=mid+1;
    }
}

bool f(int l){
    for(int st=0;st+l<=n;st++){

    }
}

int main()
{
    scanf("%d%d",&n,&k);
    getchar();
    for(int i=0;i<n;i++)
    v[i]=getchar()-'0';
    for(int i=0;i<n;i++)
        cnt[i+1]=cnt[i]+v[i],
        psa[i+1]=psa[i]+i*v[i];
    return 0;
}
