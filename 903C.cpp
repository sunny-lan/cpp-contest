#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    int maxi=0;
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        cnt[a]++;
        maxi=max(maxi, cnt[a]);
    }
    printf("%d\n", maxi);
}
