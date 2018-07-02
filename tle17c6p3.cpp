#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;scanf("%lld", &n);
    ll on=n;
    ll kust=1;
    ll sum=0;
    vector<ll> ku;
    while(n>1){
        ku.push_back(kust);
        sum+=kust;
        kust<<=1;
        n>>=1;
    }
    if(on-sum>0)
        ku.push_back(on-sum);
    printf("%d\n", ku.size());
    for(ll i:ku)
        printf("%lld ", i);

}
