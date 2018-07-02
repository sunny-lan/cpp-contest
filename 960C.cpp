#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll x,d;scanf("%I64d %I64d", &x,&d);
    int cur=40;
    vector<ll> arr;
    ll cval=1;
    while(x){
        ll sm=(1ll<<cur)-1;
        if(sm>x){
        cur--;continue;}
        for(int i=0;i<cur;i++)
            arr.push_back(cval);
        cval+=d+1;
        x-=sm;
    }
    printf("%d\n", arr.size());
    for(ll i:arr)
        printf("%I64d ", i);
}
