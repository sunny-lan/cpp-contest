#include<bits/stdc++.h>
using namespace std;

#define MAXN 100

int t[MAXN];

int main(){
    int n,a;scanf("%d%d",&n,&a);
    a--;
    for(int i=0;i<n;i++)scanf("%d", &t[i]);
    int tot=0;
    for(int x=a,y=a;x>=0||y<n;x--,y++){
        int cit=0, crim=0;
        if(x>=0)cit++, crim+=t[x];
        if(y!=x && y<n)cit++, crim+=t[y];
        if(cit==crim)
            tot+=crim;
    }
    printf("%d\n", tot);
}

