#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mp[64][27];

int conv(char c)
{
    if(c=='_')
        return 26;
    return c-'A';
}

char conv(int i)
{
    if(i==26)
        return '_';
    return 'A'+i;
}

int main()
{
    ios::sync_with_stdio(true);
    cin.tie(NULL);
    for(int i=0; i<27; i++)
    {
        string s;
        cin >>s;
        mp[0][i]=conv(s[0]);
    }
    int n;
    string t;
    cin >> n>>t;
    ll bs=2, lvl=1;
    while(bs<=n)
    {
        for(int i=0; i<27; i++)
            mp[lvl][i]=mp[lvl-1][mp[lvl-1][i]];
        bs*=2,lvl++;
    }
    lvl=0;
    while(n>0)
    {
        if(n&1)
        {
            for(int i=0; i<t.length(); i++)
                t[i]=conv(mp[lvl][conv(t[i])]);
        }
        lvl++;
        n>>=1;
    }
    cout << t<<endl;
}
