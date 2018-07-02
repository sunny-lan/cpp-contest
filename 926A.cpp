#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll l,r;
    scanf("%I64d %I64d", &l, &r);
    int cnt=0;
    for(int tw=0;tw<32;tw++){
        for(int th=0;th<20;th++){
                ll alt=pow(2,tw)*pow(3,th);
            if(alt>=l && alt<=r)
            cnt++;
        }
    }
    printf("%d", cnt);
}
