#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;cin >>s;
    int n=s.length();
    char cur='a';
    for(int i=0;i<n;i++){
        if(cur=='{')break;
        if(s[i]<=cur){
            s[i]=cur;
            cur++;
        }
    }
    if(cur=='{'){
        cout << s<<endl;
    }else{
        cout <<-1<<endl;
    }
}
