#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

int hbit(int a){
    int x=0;
    while(a)x++,a>>=1;
    return x;
}

#define MAXN 200000

ll bit[MAXN];
void update(int p, ll v){
    for(p++;p<MAXN;p+=p&-p)bit[p]+=v;
}
ll query(int p){
    ll res=0;
    for(p++;p>0;p-=p&-p)res+=bit[p];
    return res;
}

int n,q,bs,bc;
int a[MAXN];
int cand[32][2];

int main(){
    scanf("%d %d", &n, &q);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        update(i, a[i]);
    }
    for(int i=0;i<q;i++){
        int p,x;scanf("%d %d", &p, &x);
        p--;
        printf("%d\n",);
    }
}

