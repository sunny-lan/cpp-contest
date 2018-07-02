#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 6

int m[MAXN][MAXN];
bool adj[MAXN][MAXN];

int main(){
    int n;scanf("%d", &n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         scanf("%d", &m[i][j]);

    vector<pii> pos;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
    pos.push_back({i,j});

    for(int i=0;i<1<<pos.size();i++){
        memset(adj, false, sizeof adj);
        int cd=0;
        for(int j=0;j<pos.size();j++)
            if((i>>j)&1)
             adj[pos[j].f][pos[j].s]=true,
             adj[pos[j].s][pos[j].f]=true,cd++;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                int alt;
                if(x==y)alt=0;
                else{
                        alt=0;
//                        int mut=0;
                    for(int k=0;k<n;k++){
                        if(k==x||k==y)continue;
                        if(adj[x][k] && adj[y][k])
                        alt++;
                    }
                }
                if(m[x][y]!=alt)goto outer;
            }
        }
        printf("%d\n", cd);
        for(int j=0;j<pos.size();j++)
            if((i>>j)&1){
                printf("%d %d\n", pos[j].f+1,pos[j].s+1);
            }
            return 0;
        outer:continue;
    }
    printf("Impossible");
}
