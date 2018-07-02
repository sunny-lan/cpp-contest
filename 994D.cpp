#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

pii a[12], b[12];

pii ree(pii a){
    return {min(a.f, a.s), max(a.f, a.s)};
}

bool mtch[10];
bool fa[13], sa[13];

int main(){
    int n,m;scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
        scanf("%d %d", &a[i].f, &a[i].s), a[i]=ree(a[i]);

    for(int i=0;i<m;i++){
        scanf("%d %d", &b[i].f, &b[i].s), b[i]=ree(b[i]);
        bool ff=false, ss=false;
        for(int j=0;j<n;j++){
            if(b[i]==a[j])
                continue;
            int nm=-1;
            if(a[j].f==b[i].f)
                ff=true,fa[j]=true,
                nm=a[j].f;
            if(a[j].f==b[i].s)
                ss=true,fa[j]=true,
                nm=a[j].f;
            if(a[j].s==b[i].s)
                ss=true,sa[j]=true,
                nm=a[j].s;
            if(a[j].s==b[i].f)
                ff=true,sa[j]=true,
                nm=a[j].s;
            if(nm==-1)continue;
            mtch[nm]=true;
        }
        if(ff && ss)
        {
            printf("-1\n");
            return 0;
        }
    }

    for(int i=0;i<n;i++)
    if(fa[i] && sa[i]){
            printf("-1\n");
            return 0;
    }

    int cnt=0, nm;
    for(int i=1;i<10;i++)
        if(mtch[i])cnt++, nm=i;

    if(cnt==1){
        printf("%d\n", nm);
        return 0;
    }

    printf("0\n");
}
