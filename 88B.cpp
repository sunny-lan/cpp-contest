#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

unordered_map<char,bool> canshf;
unordered_map<char,bool> has;
string aa[30];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x;cin >>n>>m>>x;
    for(int i=0;i<n;i++)
        cin >>aa[i];
        bool fl=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(aa[i][j]=='S'){fl=true;
                for(int l=0;l<n;l++){
                    for(int k=0;k<m;k++){
                        int dx=l-i, dy=k-j;
                        if(dx*dx+dy*dy<=x*x)
                            canshf[aa[l][k]]=true;
                    }
                }
            }else{
                has[aa[i][j]]=true;
                }
        }
    }
    int q;
    string t;cin>>q >>t;
    int cnt=0;
    for(char c:t)
    {
        if(!has[tolower(c)]){
            printf("-1\n");
            return 0;
        }
        if(c!=tolower(c))
        {
            if(fl){
                if(!canshf[tolower(c)])
                    cnt++;
            }else{
                printf("-1\n");
            return 0;
            }
        }
    }
    printf("%d\n", cnt);
}

