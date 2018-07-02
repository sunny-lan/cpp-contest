#include<bits/stdc++.h>
using namespace std;

#define MAXN 2001

bitset<MAXN> g[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;cin >>m>>n;
    for(int i=0;i<m;i++){
        string s;cin >>s;
        for(int j=0;j<n;j++)
            if(s[j]=='#')
                g[i][j]=1;
        for(int j=0;j<i;j++)
        if((g[j]&g[i]).count()>=2){
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
}
