#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt[10];
int od[10];

ll multisetChoose(int k){
    ll res=1;
    for(int i=1;i<=k;i++)res*=i;
    for(int i=0;i<10;i++)
        for(int j=1;j<=cnt[i];j++)
            res/=j;
    return res;
}

ll tot=0;

void ff(int x=0, int len=0){
    if(x==10){
        tot+=multisetChoose(len);
        if(cnt[0]>0){
            cnt[0]--;
            tot-=multisetChoose(len-1);
            cnt[0]++;
        }
    }else{
        if(od[x]==0)ff(x+1, len);
        else
        for(cnt[x]=1;cnt[x]<=od[x]; cnt[x]++)
            ff(x+1, len+cnt[x]);
    }
}

int main()
{
    string s;
    cin >>s;
    int n=s.length();
    for(char c:s)
        od[c-'0']++;
    ff();
    printf("%lld\n", tot);
}
