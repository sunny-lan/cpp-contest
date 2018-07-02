#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char arr[3][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ch=0,x=0,o=0;scanf("%d",&n);
   while(n){
        char c=getchar();
        if(c=='X' || c=='O' ||c=='.'){
            if(c=='X')
                x++;
            else if(c=='O')
                o++;
            arr[ch/3][ch%3]=c;
            ch++;
            if(ch==9){
                bool xwin=false,altx=true;
                bool owin=false,alto=true;
                for(int sel=0;sel<3;sel++){
                    bool xx=true, xx2=true;
                    bool oo=true, oo2=true;
                    for(int nm=0;nm<3;nm++){
                        if(arr[sel][nm]=='.'||arr[sel][nm]=='O')
                        xx=false;

                        if(arr[nm][sel]=='.'||arr[nm][sel]=='O')
                        xx2=false;

                         if(arr[sel][nm]=='.'||arr[sel][nm]=='X')
                        oo=false;

                        if(arr[nm][sel]=='.'||arr[nm][sel]=='X')
                        oo2=false;
                    }
                    if(arr[sel][sel]=='.'||arr[sel][sel]=='O')
                        altx=false;

                    if(arr[sel][sel]=='.'||arr[sel][sel]=='X')
                        alto=false;
                    xwin|=xx|xx2;
                    owin|=oo|oo2;
                }
                xwin|=altx;
                owin|=alto;
                 if((x==o&&!xwin) || (x==o+1&&!owin)){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
                ch=x=o=0;
                n--;
            }
        }
    }
}


