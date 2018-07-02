#include <bits/stdc++.h>
using namespace std;

#define MAXN 501

string mp[MAXN];
int r,c;
bool g(int ro,int co){
    if(ro< 0||co<0||ro>=r||co>=c)
        return false;
    return mp[ro][co]=='S';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>r>>c;
    for(int i=0;i<r;i++){
        cin >>mp[i];
        for(int j=0;j<c;j++)
            if(mp[i][j]=='.')
            mp[i][j]='D';
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(mp[i][j]=='W')
    if(g(i+1, j)||g(i-1, j)||g(i, j+1)||g(i, j-1))
    {
        cout <<"No"<<endl;return 0;
    }

   cout <<"Yes"<<endl;
    for(int i=0;i<r;i++)
       cout << mp[i]<<endl;
}
