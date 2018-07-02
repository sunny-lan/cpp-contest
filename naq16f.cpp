#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define MAXL 19
#define MAXB 1024

int l;
string p;

vector<pll> olst;
int mout[MAXL], bout[MAXL];
int tm=0;

int f(int i, int m, int c){
    if(i==l && c==0){
        ll mn, bv;
        for(int j=i-1;j>=0;j--)
            mn=mout[j]+mn*10;
        for(int j=i-1;j>=0;j--)
            bv=bout[j]+bv*10;
        olst.push_back({bv, mn});
        if(olst.size()==5000)
            return -1;
        return 1;
    }
    for(int md=0;md<10;md++){
        if((tm>>md)&1)continue;
        int nm=m|(1<<md);

    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> p;
    reverse(p.begin(), p.end());
    l=p.length();
    for(char c:p)
        tm|=1<<(c-'0');

}
