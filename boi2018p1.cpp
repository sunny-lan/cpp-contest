#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 100000

unordered_map<string,bool> res;
string ppl[MAXN];
unordered_map<string,string> p;
unordered_map<string,int> id, od;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin >>n;
    for(int i=0;i<n;i++)
    {
        string a,b;cin >>a>>b;
        ppl[i]=a;
        p[a]=b;
        id[b]++;
        od[a]++;
    }
    int cnt=0;
    queue<string> q;
    vector<string> rs;
    for(int i=0;i<n;i++){
        string a=ppl[i];
            if(id[a]==0)q.push(a);
    }
    while(!q.empty()){
        string  nxt=q.front();
        q.pop();
        rs.push_back(nxt);
        if(p[nxt]==nxt)continue;
        if(--id[p[nxt]]==0)
            q.push(p[nxt]);
    }

    for(string a:rs){
        if( !res[a] && !res[p[a]] && p[p[a]]!=a && id[p[a]]==0){
            res[a]=res[p[a]]=true;
//            cout << p[a] << " to "<<a<<endl;
            p[p[a]]=a;
            cnt++;
        }
    }

    for(int i=0;i<n;i++){
        string a=ppl[i];
        if( !res[a] && !res[p[a]] && (p[a]==a ||p[p[a]]!=a)){
            res[a]=res[p[a]]=true;
//            cout << p[a] << " to "<<a<<endl;
            p[p[a]]=a;
            cnt++;
        }
    }
    string nxt="";
    for(int i=0;i<n;i++){
        string a=ppl[i];
        if(p[a]==a || p[p[a]]!=a){
            if(nxt=="")
                nxt=a;
            else{
                p[a]=nxt;
                p[nxt]=a;
//                cout << a<< " to "<<nxt<<endl;
//                cout << nxt<< " to "<<a<<endl;
                cnt+=2;
                nxt="";
            }
        }
    }

    if(nxt=="")
        printf("%d\n", cnt);
    else{
        printf("-1\n");
    }
}
