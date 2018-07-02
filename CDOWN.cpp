#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define MAXN 1000

int idx;
unordered_map<string,int> ord;
string car[MAXN];
int gt(string nm){
    if(ord.count(nm)==0)car[idx]=nm, ord[nm]=idx++;
    return ord[nm];
}

vector<int> ch[MAXN];

int dp[MAXN][MAXN];
int f(int i,int d){
    if(d==0)return 1;
    int &res=dp[i][d];
    if(res!=-1)return res;
    res=0;
    for(int k:ch[i])
        res+=f(k, d-1);
    return res;
}

int n,d;
int ptr[MAXN];
bool pred(int a, int b){
    int ra=f(a, d), rb=f(b,d);
    if(ra==rb)return car[a]<car[b];
    return ra>rb;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >>t;
    for(int test=1;test<=t;test++){
        cin >>n>>d;

        for(int i=0;i<MAXN;i++)
            ch[i].clear();
        ord.clear();
        idx=0;
        memset(dp, -1, sizeof dp);

        for(int i=0;i<n;i++){
            string a;int k;cin >>a>>k;
            ptr[i]=gt(a);
            for(int j=0;j<k;j++){
                string b;cin >>b;
                ch[ptr[i]].push_back(gt(b));
            }
        }

        sort(ptr, ptr+n, pred);

        cout << "Tree "<<test<<":"<<endl;
        int changes=0;
        for(int i=0;i<n ;i++){
            int id=ptr[i];
            int rs=f(id,d);
            if(rs==0)break;
            if(i&&rs!=f(ptr[i-1], d))
            changes++;
            if(i&&rs!=f(ptr[i-1], d)&&i>=3)
                break;
            if(changes==3)break;
            cout <<car[id]<<" "<<rs<<endl;
        }
        cout <<endl;
    }
}

