#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 200002

int N,M;
pii h[MAXN];
ll psa[MAXN];
pair<ll,ll> tower[MAXN];
vector<pair<int,pair<pii,int>>> q;
vector<pair<int,ll>> psaPeople;
vector<int> sizePsa;

ll bit[MAXN];
void update(int p, int v){
    for(p++;p<MAXN;p+=p&-p)
        bit[p]+=v;
}
ll query(int p){
    ll res=0;
    for(p++;p>0;p-=p&-p)
        res+=bit[p];
    return res;
}

ll bit2[MAXN];
void update2(int p, int v){
    for(p++;p<MAXN;p+=p&-p)
        bit2[p]+=v;
}
ll query2(int p){
    ll res=0;
    for(p++;p>0;p-=p&-p)
        res+=bit2[p];
    return res;
}


int main() {
    scanf("%d",&N);
    for(int i = 0 ; i<N;i++){
        scanf("%lld%lld",&tower[i].f,&tower[i].s);
        h[i]={tower[i].f,i};
        psa[i+1]=tower[i].s+psa[i];
    }
    sort(h,h+N);
    reverse(h,h+N);
    int idx=1;
    psaPeople.push_back({-(1<<30),0});
    sizePsa.push_back(0);
    sizePsa.push_back(1);
    psaPeople.push_back({-h[0].f,tower[h[0].s].s});
    for(int i = 1;i<N;i++){
        if(-h[i].f==psaPeople[idx].first){
            psaPeople[idx].second+=tower[h[i].s].s;
            sizePsa[idx]++;
        }else{
            psaPeople.push_back({-h[i].f,tower[h[i].s].s+psaPeople[idx].s});
            sizePsa.push_back(sizePsa[idx]+1);
            idx++;
        }
    }
    scanf("%lld",&M);
    int a,b,c;
    for(int i = 0 ; i<M;i++){
        scanf("%d%d%d",&a,&b,&c);
        q.push_back({--a,{{--b,--c},i}});
    }
    sort(q.begin(),q.end());
//    reverse(q.begin(),q.end());
    int ptr=N-1;
    int lptr=0, rptr=0;
    for(auto cur:q){
        int dst=h[cur.f].f;
        while(ptr>=0 && h[ptr].f<dst)
            update(h[ptr].s, tower[h[ptr].s].s),ptr--;

        double sureVal=query(cur.s.f.s)-query(cur.s.f.f-1);//step 1
        int cust=lower_bound(psaPeople.begin(),psaPeople.end(),pair<int,ll>{-dst-1,0ll})-psaPeople.begin();
        double probRemove=psaPeople[cust].s-psaPeople[cust-1].s;//step 2
        double sureRemove=psaPeople[cust-1].s;
        probRemove*=(double)(cur.f-sizePsa[cust-1]+1);
        probRemove/=(double)(sizePsa[cust]-sizePsa[cust-1]);

//        cout << "dst="<<dst<<endl;
        while(rptr<N && h[rptr].f>=dst){
//            cout << "ins "<<tower[h[rptr].s].f<<" to" <<tower[h[rptr].s].s<<endl;
            update2(h[rptr].s, tower[h[rptr].s].s),rptr++;
        }

        while(lptr<N && h[lptr].f>dst){
//            cout << "rem "<<tower[h[lptr].s].f<<" to" <<tower[h[lptr].s].s<<endl;
            update2(h[lptr].s, -tower[h[lptr].s].s),lptr++;
        }

//        cout << lptr<<" g" <<rptr<<endl;

        double kust=query2(cur.s.f.s)-query2(cur.s.f.f-1);
//        cout<<kust<<" "<<sureVal<<endl;
        kust*=(double)((sizePsa[cust]-sizePsa[cust-1])-(cur.f-sizePsa[cust-1]+1));
        kust/=(double)(sizePsa[cust]-sizePsa[cust-1]);
//        cout<<sureRemove<<endl;
        printf("%lf\n",sureVal+probRemove+sureRemove+kust);
    }


}

