#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001

bool vf[MAXN][MAXN], vb[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;cin >>s;
    int n=s.length(), res=0;
    for(int i=0;i<n;i++){
        int op=0, qu=0;
        for(int j=i;j<n;j++){
            if(s[j]=='(')
                op++;
            if(s[j]=='?')
                qu++;
            if(s[j]==')'){
                if(op>0)
                    op--;
                else{
                    if(qu>0)
                        qu--;
                    else break;
                }
            }
            if(qu-op>=0 && (qu-op)%2==0)
                vf[i][j]=true;
        }
         op=0, qu=0;
        for(int j=i;j>=0;j--){
            if(s[j]==')')
                op++;
            if(s[j]=='?')
                qu++;
            if(s[j]=='('){
                if(op>0)
                    op--;
                else{
                    if(qu>0)
                        qu--;
                    else break;
                }
            }
            if(qu-op>=0 && (qu-op)%2==0)
                vb[i][j]=true;
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(vf[i][j] && vb[j][i])
        res++;

    printf("%d\n", res);
}
