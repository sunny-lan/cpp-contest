#include <bits/stdc++.h>
using namespace std;

int main(){
   int a,b;scanf("%d%d", &a,&b);
   int yr=0;
   for(;a<=b;yr++)
    a*=3, b*=2;
   printf("%d\n", yr);
}
