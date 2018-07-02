#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin >>n;
    for(int i=0;i<n;i++){
        string a,b;cin >>a>>b;
        if(a.length()<b.length())swap(a,b);
        a+='0';
        for(int i=0;i<a.length();i++){
            int tot=a[i]-'0';
            if(i<b.length())
                tot+=b[i]-'0';
            if(tot>=10)
                a[i+1]++,tot-=10;
            a[i]=tot+'0';
        }
        while(a.back()=='0')
            a=a.substr(0,a.length()-1);
        while(a[0]=='0')
            a=a.substr(1);
        cout <<a<<endl;
    }
}

