#include <bits/stdc++.h>
using namespace std;

int main(){
    int tot=0;
    long long kst=1;
    while(kst<1e18 ){
        int x;cin >>x;
        tot+=x;
        kst*=x;
    }

    int x;cin>>x;
    cout << "a"<<x<<" "<<kst<<endl;
    while(1);
}
