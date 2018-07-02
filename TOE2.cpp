#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char arr[3][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ch=0,x=0,o=0;
   while(!feof(stdin)){
        char c=getchar();
        if(c=='X' || c=='O' ||c=='.'){
            if(c=='X')
                x++;
            else if(c=='O')
                o++;
            arr[ch/3][ch%3]=c;
            ch++;
            if(ch==9){
                bool xwin=false,x3=true,x4=true;
                bool owin=false,o3=true,o4=true;
                for(int sel=0;sel<3;sel++){
                    bool xx=true, x2=true;
                    bool oo=true, o2=true;
                    for(int nm=0;nm<3;nm++){
                        if(arr[sel][nm]=='.'||arr[sel][nm]=='O')
                        xx=false;

                        if(arr[nm][sel]=='.'||arr[nm][sel]=='O')
                        x2=false;

                         if(arr[sel][nm]=='.'||arr[sel][nm]=='X')
                        oo=false;

                        if(arr[nm][sel]=='.'||arr[nm][sel]=='X')
                        o2=false;
                    }
                    if(arr[sel][sel]=='.'||arr[sel][sel]=='O')
                        x3=false;

                    if(arr[sel][sel]=='.'||arr[sel][sel]=='X')
                        o3=false;

                    if(arr[sel][2-sel]=='.'||arr[sel][2-sel]=='O')
                        x4=false;

                    if(arr[sel][2-sel]=='.'||arr[sel][2-sel]=='X')
                        o4=false;
                    xwin|=xx|x2;
                    owin|=oo|o2;
                }
                xwin|=x3|x4;
                owin|=o3|o4;
                 if((xwin!=owin||x+o==9)&&((x==o&&!xwin) || (x==o+1&&!owin))){
                    printf("valid\n");
                }else{
                    printf("invalid\n");
                }
                ch=x=o=0;
            }
        }
    }
}


