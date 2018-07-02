#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    int h=n/100;
    n-=h*100;
    int tw=n/20;
    n-=tw*20;
    int tn=n/10;
    n-=tn*10;
    int f=n/5;
    n-=f*5;
    printf("%d\n", h+tw+tn+f+n);
}
