#include <bits/stdc++.h>
using namespace std;

string s[100000];
int k[100000];

int main(){
    int n;cin >>n;

    for(int i=0;i<n;i++){
        cin >>s[i]>>k[i];
    }

    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(j==i)continue;
            if(k[i]>k[j])
                cnt++;
        }

        if(cnt*2>=n)
            cout << s[i]<<" is cute! <3"<<endl;
        else
            cout << s[i]<<" is not cute. </3"<<endl;
    }
}
