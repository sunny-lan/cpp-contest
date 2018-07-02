#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    int prev=-1;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        int a;scanf("%d", &a);
        if(prev!=-1)
            mini=min(mini, max((prev-1),(1000000-a)));
        else
            mini=min(mini, 1000000-a);
        prev=a;
    }
    mini=min(mini, prev-1);
    printf("%d\n", mini);
}
