#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,h;scanf("%d %d", &n,&h);
    int tot=0;
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d", &a);
        if(a>h)
            tot++;
        tot++;
    }
    printf("%d\n", tot);
}
