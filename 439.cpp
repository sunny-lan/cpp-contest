#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define MAXN 8

bool vis[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,d;
    while(cin >>s>>d){
        int x=s[0]-'a',y=s[1]-'1';
        int dx=d[0]-'a',dy=d[1]-'1';
        memset(vis, false, sizeof vis);
        queue<pair<pii,int>> q;
        q.push({{x,y},0});
        while(!q.empty()){
            pii cur=q.front().f;
            int lvl=q.front().s;
            q.pop();
            if(cur.f<0||cur.s<0||cur.f>7||cur.s>7)continue;
            if(vis[cur.f][cur.s])continue;
            vis[cur.f][cur.s]=true;
            if(cur.f==dx && cur.s==dy){
                cout<<"To get from "<<s<<" to "<<d<<" takes "<<lvl<<" knight moves."<<endl;
                break;
            }
            q.push({{cur.f-1,cur.s-2},lvl+1});
            q.push({{cur.f+1,cur.s-2},lvl+1});
            q.push({{cur.f-2,cur.s-1},lvl+1});
            q.push({{cur.f+2,cur.s-1},lvl+1});
            q.push({{cur.f-1,cur.s+2},lvl+1});
            q.push({{cur.f+1,cur.s+2},lvl+1});
            q.push({{cur.f-2,cur.s+1},lvl+1});
            q.push({{cur.f+2,cur.s+1},lvl+1});
        }

    }
}
