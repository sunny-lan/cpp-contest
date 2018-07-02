#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

vector<int> child[MAXN];

int cnt[MAXN];

int dfs(int i, int lvl=0){
    cnt[lvl]++;
    for(int j:child[i])
        dfs(j, lvl+1);
}

int main(){
    int n;scanf("%d\n", &n);
    for(int i=1;i<n;i++){
        int p;scanf("%d", &p);
        p--;
        child[p].push_back(i);
    }

    dfs(0);

    int res=0;
    for(int i=0;i<n;i++)
        if(cnt[i]>0)
        if(cnt[i]%2==1)
        res++;

    printf("%d\n", res);
}
