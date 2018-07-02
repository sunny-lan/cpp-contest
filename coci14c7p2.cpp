#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100001

ll dk[MAXN];
ll t[MAXN];

int main(){
    ll n,k;scanf("%lld %lld", &n, &k);
    k--;
    for(int i=0;i<n;i++)
    {
        ll v;scanf("%lld", &v);
        v--;dk[v]=i;
    }

    ll ck=dk[0], tot=0;
    for(int i=1;i<n;i++){
        ll need=dk[i];
        if(need<ck)
            tot+=(need+n)-ck;
        else
            tot+=need-ck;
        ck=need;
        t[i]=tot;
    }

    ll roundtrip=tot;
    {
        ll need=dk[0];
        if(need<ck)
            roundtrip+=(need+n)-ck;
        else
            roundtrip+=need-ck;
    }

    printf("%lld\n", roundtrip*(k/n)+t[k%n]+dk[0]);
}
