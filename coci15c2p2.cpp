#include <bits/stdc++.h>
using namespace std;

#define MAXN 21

int kust[MAXN];

int main(){
    int n,m;scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a,b;scanf("%d %d", &a, &b);
        a--,b--;
        kust[a]|=1<<b;
        kust[b]|=1<<a;
    }

    int cnt=0;

    for(int i=0;i<1<<n;i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                if(kust[j]&i)
                    goto outer;
            }
        }
        cnt++;
        outer:continue;
    }

    printf("%d", cnt);
}
