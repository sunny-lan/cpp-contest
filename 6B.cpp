#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string mp[100];

unordered_map<char,bool> kek;
int n,m;
void chk(int i, int j){
    if(i<0||j<0||i>=n ||j>=m)return;
    kek[mp[i][j]]=true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char p;
    string tmp;
    cin >>n>>m>>tmp;
    p=tmp[0];
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]==p)
                chk(i,j+1),
                chk(i,j-1),
                chk(i+1,j),
                chk(i-1,j);
    kek[p]=false;
    kek['.']=false;
    int cnt=0;
    for(auto lel:kek)if(lel.second)cnt++;
    printf("%d\n", cnt);
}

