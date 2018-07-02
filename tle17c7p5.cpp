#include <bits/stdc++.h>
using namespace std;

#define MAXN 101
double adj[MAXN][MAXN], ora[MAXN][MAXN];

int x[MAXN], y[MAXN], nd[MAXN];

bool assigned[MAXN];

int main(){
    int n;scanf("%d %d", &n);
    for(int i=0;i<n;i++)
        scanf("%d %d", &x[i], &y[i]);
    for(int i=0;i<n;i++){
        double a,b;scanf("%lf %lf", &a, &b);
        for(int j=0;j<n;j++){
            double dx=x[j]-a,dy=y[j]-b;
            ora[i][j]=ora[j][i]=adj[i][j]=adj[j][i]=sqrt(dx*dx+dy*dy);
        }
    }
    for(int i=0;i<n;i++){
        double mini=INFINITY;
        for(int j=0;j<n;j++)
            mini=min(mini, adj[i][j]);
        for(int j=0;j<n;j++)
            adj[i][j]-=mini;
    }
     for(int i=0;i<n;i++){
        double mini=INFINITY;
        for(int j=0;j<n;j++)
            mini=min(mini, adj[j][i]);
        for(int j=0;j<n;j++)
            adj[j][i]-=mini;
    }

    double tot=0;
    for(int i=0;i<n;i++){
        int c=-1;
        for(int j=0;j<n;j++){
            if(adj[i][j]==0)

        }
    outer:continue;
    }

}
