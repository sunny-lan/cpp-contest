#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii, int> ppi;
#define f first
#define s second

pii operator+(pii a, pii b)
{
    return {a.f+b.f, a.s+b.s};
}

pii operator*(int a, pii b)
{
    return {a*b.f, a*b.s};
}

bool ok(pii a, ll lim)
{
    return ((ll)a.f)*a.f+((ll)a.s)*a.s<=lim*lim;
}

#define MAXN 100000

int n;
int ans[MAXN];
int idx;
vector<pii> adj[MAXN*2];
int kek[]= {1,-1};

void cmb(vector<ppi>& in)
{
    ll lim=1000000;
    if(in.size()==2)
        lim=1500000;
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            for(int k=0; k<2; k++)
                for(int l=0; l<2; l++)
                {
                    int a=kek[k], b=kek[l];
                    pii cmb=a*in[i].f+b*in[j].f;
                    if(ok(cmb, lim))
                    {
                        adj[idx-n].push_back({in[i].s,a}), adj[idx-n].push_back({in[j].s,b});
                        in.erase(in.begin()+j), in.erase(in.begin()+i);
                        in.push_back({cmb, idx++});
                        return;
                    }
                }
        }
    }
}

void dfs(int i, int s=1){
    if(i<n){ans[i]=s;return;}
    for(pii k:adj[i-n])
        dfs(k.f, s*k.s);
}

int main()
{
    scanf("%d", &n);
    queue<ppi> q;
    for(int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d %d", &x,&y);
        q.push({{x,y},idx++});
    }
    while(q.size()>2)
    {
        vector<ppi> res;
        for(int i=0; i<3; i++)
            res.push_back(q.front()), q.pop();
        cmb(res);
        for(ppi k:res)
            q.push(k);
    }
    vector<ppi> reet;
    for(int i=0;i<2;i++)
    reet.push_back(q.front()), q.pop();
    cmb(reet);
    dfs(reet.front().s);
    for(int i=0;i<n;i++)printf("%d ", ans[i]);
}
