#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000
#define MAXV 1000001

bool v[MAXV];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;scanf("%d", &a);
        v[a]=true;
    }
    for(int k=MAXV;k>=1;k--){
        int cnt=0;
        for(int m=k;m<MAXV;m+=k)
        if(v[m])
        if(++cnt>=2)
        {
            printf("%d\n", k);
            return 0;
        }
    }
}
