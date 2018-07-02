#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010*1010
vector<int> adj[MAXN];
bool v[MAXN];
int n,m;

void dfs(int i)
{
    if(v[i])
        return;
    v[i]=true;
    for(int j:adj[i])
        dfs(j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n>>m;
    for(int i=0; i<n; i++)
    {
        string l;
        cin >> l;
        for(int j=0; j<m; j++)
        {
            int y,x=i*m+j;
            if(l[j]=='N')
                if(i>0)
                    y=(i-1)*m+j;
            if(l[j]=='S')
                if(i<n-1)
                    y=(i+1)*m+j;
            if(l[j]=='E')
                if(j<m-1)
                    y=i*m+(j+1);
            if(l[j]=='W')
                if(j>0)
                    y=i*m+(j-1);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    int cnt=0;
    for(int i=0; i<n*m; i++)
            if(!v[i])
            {
                cnt++;
                dfs(i);
            }
    printf("%d\n", cnt);
}
