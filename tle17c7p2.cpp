#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second
#define day (60*24)

#define MAXN 100000

vector<pii> fl[MAXN];

int main(){
    int n,m;scanf("%d %d", &n,&m);
    for(int i=0;i<m;i++){
        int a; pii kust;
        scanf("%d %d %d", &a, &kust.f, &kust.s);
        a--;
        kust.f*=60, kust.s*=60;
        fl[a].push_back(kust);
    }
    int t=0;
    for(int i=0;i<n-1;i++){
        int bn=INT_MAX;
            int td=(t+20)%day;

//            cout << "airport "<<i<<" td="<<td<<endl;

//    printf(" current Day %d Hour %d\n", t/day, ((t-t/day))/60);
        for(pii k:fl[i]){
//            cout << " consider flight "<<k.f<<" "<<k.s<<endl;
            if(td<=k.f){
//                cout << " valid nxt="<<(t/day)*day+k.f+k.s<<endl;
                bn=min(bn, (t/day)*day+k.f+k.s);
            }else{
                bn=min(bn, (t/day+1)*day+k.f+k.s);
            }
        }
        t=bn+20;
    }
    printf("Day %d Hour %d\n", t/day, ((t-(t/day)*day)+59)/60);
}
