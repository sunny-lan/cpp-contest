#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

bool canFirstWin(ll a, ll b){
    if(a>b)swap(a,b);
    if(a==0)return false;
    if(b-a>=a)return true;
    return !canFirstWin(a,b%a);
}

int main(){
    while(1){
        ll a,b;scanf("%lld%lld",&a,&b);
        if(a==0&&b==0)return 0;
        printf(canFirstWin(a,b)?"Stan wins\n":"Ollie wins\n");
    }
}


