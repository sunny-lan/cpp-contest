#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define MAXX 1000000000ll
#define MAXN 100000
unordered_set<ll> pos;

ll conv(int r, int c){
    return r*MAXX+c;
}

queue<pair<pii,int>> q;

unordered_map<ll,bool> inq;

void chk(int r, int c, int lvl){
    if(pos.count(conv(r,c))>0 && !inq[conv(r,c)])
    q.push({{r,c},lvl+1}),
        inq[conv(r, c)]=true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x0,y0,x1,y1,n;scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&n);
    x0--,y0--, x1--,y1--;
    for(int i=0;i<n;i++){
        int r,a,b;scanf("%d%d%d",&r,&a,&b);
        r--,a--,b--;
        for(int j=a;j<=b;j++)
            pos.insert(conv(r,j));
    }
    q.push({{x0,y0},0});
    while(!q.empty()){
        pii cur=q.front().f;
        int lvl=q.front().s;
        q.pop();
        inq[conv(cur.f, cur.s)]=false;
        if(cur.f==x1 && cur.s==y1)
        {
            printf("%d\n",lvl);
            return 0;
        }
        if(pos.count(conv(cur.f, cur.s))==0)continue;
        pos.erase(conv(cur.f, cur.s));
        chk(cur.f+1, cur.s,lvl);
        chk(cur.f-1, cur.s,lvl);
        chk(cur.f, cur.s+1,lvl);
        chk(cur.f, cur.s-1,lvl);
        chk(cur.f-1, cur.s-1,lvl);
        chk(cur.f-1, cur.s+1,lvl);
        chk(cur.f+1, cur.s-1,lvl);
        chk(cur.f+1, cur.s+1,lvl);
    }
    printf("-1\n");
}

