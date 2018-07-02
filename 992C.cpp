#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+7;

int main(){
    ll x,k;scanf("%lld %lld", &x, &k);
    if(x==0){
        printf("0\n");return 0;
    }
    ll cur=2, res=1;
    while(k){
        if(k&1)
            res*=cur, res%=mod;
        cur*=cur, cur%=mod;
        k>>=1;
    }
    printf("%lld\n", ((2*x%mod-1+mod)%mod*res%mod+1)%mod);
}
