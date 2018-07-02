#include <bits/stdc++.h>
using namespace std;

int main(){
    int x2;scanf("%d", &x2);
    vector<ll> primes;
    for(ll i=2;i*i<=x2;i++){
        for(int ll j=2;j*j<=i;j++){
            if(i%j==0)
                goto cacner;
        }
        primes.push_back(i);
        cacner:continue;
    }

    for(ll p:primes){
        if(x2%p!=0)continue;
        ll x1=p+1;

    }
}
