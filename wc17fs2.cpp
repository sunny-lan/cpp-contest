#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 100000

int p[MAXN],N,M;
ll res=0;
vector<pil> adj[MAXN];

int f(int x){
    if(p[x]==x)return x;
    return p[x]=f(p[x]);
}

bool mrg(int x, int y){
    int px=f(x), py=f(y);
    if(px==py)return false;
    p[px]=py;
    return true;
}

vector<pair<ll, pii>> cust;

int main(){
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++)
    p[i]=i;
    int a,b;
    ll c;
    for(int i = 0 ; i<M;i++){
        scanf("%d%d%lld",&a,&b,&c);
        --a;--b;
        if(c>0){
            res+=c;
            mrg(a,b);
        }else{
            cust.push_back({c,{a,b}});
        }
    }
    sort(cust.begin(),cust.end());
  reverse(cust.begin(), cust.end());
    for(auto e:cust){
        if(mrg(e.second.first,e.second.second)){
            res+=e.first;
        }
    }
    int pp=f(0);
    for(int i=0;i<N;i++)
    if(f(i)!=pp){
        printf("Impossible\n");
        return 0;
    }
    printf("%lld\n",res);
    return 0;
}
