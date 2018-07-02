#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 200000
#define MAXB 450

int n,q,bs,bc;
int a[MAXN];

unordered_map<ll, int> keks[MAXB];
ll sum[MAXB];

void recalc(int blk){
    keks[blk].clear();
    sum[blk]=0;
    int bb=blk*bs, be=min(bb+bs, n);
    for(int i=bb;i<be;i++){
        if(a[i]-sum[blk]>=0)
        keks[blk][a[i]-sum[blk]]=i;
        sum[blk]+=a[i];
    }
}

int fnd(){
    ll psum=0;
    for(int i=0;i<bc;i++){
        if(keks[i].count(psum)>0)
        return keks[i][psum];
        psum+=sum[i];
    }
    return -2;
}

int main(){
    scanf("%d %d", &n, &q);
    bs=sqrt(n);
    bc=(n+bs-1)/bs;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<bc;i++)recalc(i);
    for(int i=0;i<q;i++){
        int p,x;scanf("%d %d", &p, &x);
        p--;
        a[p]=x;
        recalc(p/bs);
        printf("%d\n", fnd()+1);
    }
}
