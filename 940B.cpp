#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n,k,a,b;
    scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
    ll cost=0;
    while(n>1){
        ll nxtmult=(n/k)*k;
        cost+=(n-nxtmult)*a;
        n=nxtmult;
        if(n==1)break;
        ll nxt=n/k;
        cost+=min(b, (n-nxt)*a);
        n=nxt;
    }
    printf("%lld", cost);
}
