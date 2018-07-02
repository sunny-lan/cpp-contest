#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

int xx[3],yy[3];
char c[3];
int ord[3]={0,1,2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<3;i++){
        char x,y;
        x=getchar();
        c[i]=getchar();
        y=getchar();
        getchar();
        xx[i]=x-'A', yy[i]=y-'A';
    }
    string ans="   ";
    do{
        for(int i=0;i<3;i++){
            if(c[i]=='<'){
                if(ord[xx[i]]>ord[yy[i]])
                    goto outer;
            }else{
                if(ord[xx[i]]<ord[yy[i]])
                    goto outer;
            }
        }
        if(ans!="   "){
            printf("Impossible\n");
            return 0;
        }
        for(int i=0;i<3;i++)
            ans[ord[i]]=i+'A';
    outer:int lol;
    }while(next_permutation(ord, ord+3));
    if(ans=="   "){
            printf("Impossible\n");
            return 0;
        }
    printf("%s\n", ans.c_str());
}
