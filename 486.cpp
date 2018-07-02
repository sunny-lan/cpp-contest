#include <iostream>
using namespace std;

int main(){
   string a,b;cin >>a>>b;
   int bul=0,cow=0;
   for(int i=0;i<4;i++)
    if(a[i]==b[i])
        bul++;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(j!=i)
        if(a[i]==b[j])
 cow++;
 printf("%d %d\n", bul, cow);
}
