#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define LIM 100001

int main(){
    int q;ll k;
    scanf("%d%lld", &q, &k);
    vector<ll> pal;
    for(int i=0;i<LIM;i++){
        string k1=to_string(i), k2=k1;
        reverse(k2.begin(), k2.end());

        ll p1=atoll((k1+k2).c_str());
        if(p1>0 &&p1%10!=0 && p1%k==0)
            pal.push_back(p1);

        k2=k2.substr(1, k2.length()-1);
//        cout << "k1="<<k1<<" k2="<<k2<<endl;
        p1=atoll((k1+k2).c_str());
        if(p1>0&&p1%10!=0 && p1%k==0)
            pal.push_back(p1);
    }
    sort(pal.begin(), pal.end());
//    for(ll i:pal)
//        printf("%lld\n", i);
//    printf("ee");
    for(int i=0;i<q;i++){
        ll m,n;scanf("%lld %lld",&m,&n);
        printf("%d\n", upper_bound(pal.begin(), pal.end(), n)-lower_bound(pal.begin(), pal.end(), m));
    }
}
