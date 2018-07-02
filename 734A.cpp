#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;string s;
   cin >>n>>s;
   int a=0,d=0;
   for(char c:s)
    if(c=='A')a++;else d++;
   if(a>d)
    printf("Anton\n");
   else if(d>a)
    printf("Danik\n");
   else
    printf("Friendship\n");
}
