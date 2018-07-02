#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 1010

int bit[MAXN];

void update(int p, int v){
    for(;p<MAXN;p+=p&-p)
        bit[p]+=v;
}

int query(int p){
    int res=0;
    for(;p>0;p-=p&-p)
        res+=bit[p];
    return res;
}

bool ye[MAXN], yeee[MAXN];

int main(){
    int n,k,m;
    scanf("%d%d%d", &n,&k,&m);
    vector<pii> kust;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a, &b,&c);
        if(c){
            kust.push_back({a,b});
        }else{
            for(int j=a;j<=b;j++)
                ye[j]=true;
        }
    }
    for(int i=1;i<=n;i++)
        if(!ye[i])
        update(i, 1);
    while(!kust.empty()){
            bool flg=true;
        for(pii rng:kust){
            if()
        }
    if(flg)break;
    }
}
