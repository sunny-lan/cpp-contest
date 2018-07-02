#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

typedef pair<int, int> pii;
typedef long long ll;
#define f first
#define s second

vector<pii> prime;
int main(){
    //freopen("C:\\Users\\sunny\\Desktop\\DATA31.txt", "r", stdin);
    for(int test=0;test<10;test++){
        prime.clear();
        int k,m;
        cin>>k>>m;

        //prime factor
        int tmp = k,mxp=sqrt(k);
        for(int i=2;i<=mxp && tmp != 1;++i){
            if(tmp%i==0){
                pii cur={i,0};
                while(tmp%i==0)
                    ++cur.s,tmp/=i;
                prime.push_back(cur);
            }
        }
        if(tmp!=1)
            prime.push_back({tmp,1});

        //binary search
        ll lo=2,hi=1LL<<60;
        while(lo<hi){
            ll mid=(lo+hi)/2;
            ll tmp = mid;
            ll fcnt=1LL<<60;
            for(int i=0;i<prime.size();++i){
                ll cnt = 0, curP = prime[i].f;
                for(int j=curP;j<=tmp;j*=j)
                    cnt+=tmp/j;
                cnt/=prime[i].s;
                fcnt=min(fcnt,cnt);
            }
            if(fcnt<m)
                lo=mid+1;
            else
                hi=mid;
        }

        cout<<lo<<"\n";
    }
}
