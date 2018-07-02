#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int sv[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,f;scanf("%d%d",&n,&f);
    ll nrm=0;
    for(int i=0;i<n;i++){
        int k,l;scanf("%d%d",&k,&l);
        int typ=min(k,l), gud=min(l,k*2);
        nrm+=typ;
        sv[i]=gud-typ;
    }
    sort(sv,sv+n);
    for(int i=0;i<f;i++)
        nrm+=sv[n-i-1];
    printf("%lld\n", nrm);
}

