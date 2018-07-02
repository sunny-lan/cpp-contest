#include <bits/stdc++.h>
using namespace std;

string s;

bool f(string x){
    if(x.empty())return false;
    if(x==s)return true;
    string t=x.substr(0, x.length()-1);
    if(x[x.length()-1]=='B')
        reverse(t.begin(), t.end());
    return f(t);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin >>n;
    for(int i=0;i<n;i++){
            string t;
        cin >> s>>t;
        if(f(t))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
