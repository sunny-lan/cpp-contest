#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    {

        int nm;scanf("%d", &nm);
        if(nm){
            printf("%d\n", abs(2-i)+abs(2-j));
            return 0;
        }
    }
}
