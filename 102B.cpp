#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

string f(string x){
    int sm=0;
    for(char c:x)
        sm+=c-'0';
    return to_string(sm);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;cin>>n;
    int cnt;
    for(cnt=0;n.length()>1;cnt++)
        n=f(n);
    printf("%d\n", cnt);
}
