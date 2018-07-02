#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 65540

int bit[MAXN];
void update(int p){
    for(p++;p<MAXN;p+=p&-p)
        bit[p]++;
}

int query(int p){
    int res=0;
    for(p++;p>0;p-=p&-p)
        res+=bit[p];
    return res;
}

int a[MAXN];
int ptr[MAXN];
bool pred(int x, int y){
    return a[x]<a[y];
}

int main(){
    int n;scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]), ptr[i]=i;
    sort(ptr, ptr+n, pred);
    unordered_map<int,int> ord;
//    int lst=-1, idx=0;
    for(int i=0;i<n;i++){
        int ii=ptr[i];
        ord[a[ii]]=i;
//        cout << "ord "<<a[ii]<<" = "<<i<<endl;
    }
    ll sm=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        sm+=cnt-query(ord[a[i]]);
//        cout << "query "<<ord[a[i]]-1<<" = "<<query(ord[a[i]]-1)<<endl;
        update(ord[a[i]]);
        cnt++;
//        cout << "update"<<ord[a[i]]<<endl;
    }
    printf("%lld\n", sm);
}
