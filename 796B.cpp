#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

bool pos[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int h;scanf("%d",&h);
        h--;
        pos[h]=true;
    }
    int cur=0;
    if(pos[cur]){
        printf("%d\n", cur+1);
        return 0;
    }
    for(int i=0;i<k;i++){
        int u,v;scanf("%d%d",&u,&v);
        u--,v--;
        if(u==cur)
            cur=v;
        else if(v==cur)
            cur=u;
    if(pos[cur]){
        printf("%d\n", cur+1);
        return 0;
    }
    }
printf("%d\n", cur+1);
}

