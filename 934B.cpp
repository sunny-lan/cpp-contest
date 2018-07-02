#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int k;
    scanf("%d", &k);
    string res="4";
    k--;
    while(k>0 )
    {
        ll nxt=atoll(res.c_str())*10;
        if(nxt>1000000000000000000ll)
            break;
        res=to_string(nxt);
        k--;
    }
    int idx=res.length()-1;
    while(k>0  )
    {
        string nxt=res;
        if(idx==-1)
        {
            printf("-1");
            return 0;
        }
        nxt[idx]='8';
        idx--;
        if(atoll(nxt.c_str())>1000000000000000000ll)
        {
            printf("-1");
            return 0;
        }
        k--;
        res=nxt;
    }
    cout <<res<<endl;
}
