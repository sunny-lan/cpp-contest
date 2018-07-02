#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

vector<int> adj[MAXN];

bool dp[MAXN][2];



int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++)
    {
        int c;
        scanf("%d", &c);
        for(int j=0; j<c; j++)
            int b;
        scanf(%d, &b);
        b--;
        adj[i].push_back(b);
    }


}
