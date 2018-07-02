#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

ll modpow(int b, int p, int m){
    ll cur=b;
    ll res=1;
    while(p){
        if(p&1)res*=cur, res%=m;
        cur*=cur;
        cur%=m;
        p>>=1;
    }
    return res;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(!feof(stdin)){
        int b,p,m;scanf("%d%d%d",&b,&p,&m);
        printf("%lld\n", modpow(b,p,m));
    }
}


