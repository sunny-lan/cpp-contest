#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAXN 26

int p[MAXN];
int f(int x)
{
    if(p[x]==x)
        return x;
    return p[x]=f(p[x]);
}

int main()
{
    for(int i=0; i<26; i++)
        p[i]=i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string a,b;
    cin >>n>>a>>b;
    vector<pair<char,char>> kust;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            int pa=f(a[i]-'a'),
                pb=f(b[i]-'a');
            if(pa==pb)
                continue;
            kust.push_back({a[i], b[i]});
            p[pa]=pb;
        }
    }
    printf("%d\n", kust.size());
    for(auto x:kust)
        printf("%c %c\n", x.first, x.second);
}
