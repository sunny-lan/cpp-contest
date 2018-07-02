#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    unordered_map<ll,bool> cnt;
    int n,m;scanf("%d %d", &n, &m);
    ll taken=0;
    for(int i=0;i<n;i++)
    {
        string s;cin >>s;
        ll res=0;
        for(int j=0;j<m;j++)
            if(s[j]=='#')
                res|=1ll<<j;
        if(cnt[res])continue;
        if((taken & res)!=0){
            printf("No");return 0;
        }
        taken|=res;
        cnt[res]=true;
    }
    printf("Yes");
}
