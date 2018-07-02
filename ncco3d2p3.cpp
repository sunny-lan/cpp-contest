#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double,int> pdi;
#define a first
#define b second

#define MAXN 50000

int n;
pii s[MAXN];
double avg(pii x){
    return x.a/(double)x.b;
}
bool pred(pii x, pii y){
    return avg(x)<avg(y);
}

int main(){
    scanf("%d", &n);
    queue<int> l;
    for(int i=0;i<n;i++)
        scanf("%d%d", &s[i].a, &s[i].b),
        l.push(i);
        l.push(-1);
    sort(s, s+n, pred);
    int tnm=0,tdn=0, rnm=0, rdn=0, lst=-1;
    double cm=0;
    stack<int> ans;
    for(int d=n-1;d>=0;d--){
        tnm+=s[d].a, tdn+=s[d].b;
        double ori=tnm/(double)tdn;
        double maxi=-INFINITY;
        int bst=-1;
        while(l.front()!=-1){
            int cur=l.front();
            l.pop();
            if(cur==lst)continue;
            double alt=s[cur].a-ori*s[cur].b;
            if(alt>0)continue;
            if(alt>maxi)
                maxi=alt, bst=cur;
            l.push(cur);
        }
        l.push(l.front());
        l.pop();
//        cm=min(cm, maxi);
//        cout << bst<<endl;
        rnm+=s[bst].a;
        rdn+=s[bst].b;
        double roger=rnm/(double)rdn;
        if(roger>ori)
            ans.push(d);
        lst=bst;
    }
    printf("%d\n", ans.size());
    while(!ans.empty())
        printf("%d\n", ans.top()), ans.pop();
}
