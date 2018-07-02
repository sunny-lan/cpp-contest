#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,y;
    string s;
    cin >>n>>x>>y>>s;
    ll cst=0;
    if(x<y)
    {
        ll cnt=0, sec=0;
        for(char c:s)
            if(c=='1')
            {
                if(cnt>0)
                    sec++;
                cnt=0;
            }
            else
                cnt++;
        if(cnt>0)
            sec++;
        if(sec>0)
            cst=(sec-1)*x+y;
    }
    else
    {
        ll cnt=0;
        for(char c:s)
            if(c=='1')
            {
                if(cnt>0)
                    cst+=y;
                cnt=0;
            }
            else
                cnt++;
        if(cnt>0)
            cst+=y;
    }
    printf("%I64d\n", cst);
}

