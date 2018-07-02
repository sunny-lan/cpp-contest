#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll,ll> f(ll a, ll b){
    if(a==0 || b==0)return {a,b};
    if(a>=2*b)
        return f(a%(2*b), b);
    if(b>=a*2)
        return f(a, b%(a*2));
    return {a,b};
}

int main(){
    ll n,m;scanf("%I64d %I64d", &n, &m);
    pair<ll,ll> res=f(n,m);
    printf("%I64d %I64d\n", res.first, res.second);
}
