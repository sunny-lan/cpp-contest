#include <bits/stdc++.h>
using namespace std;

int maxi=0;
bool v[100][100][100][100];
int ci,oi,wo,so;
int co,oo,wi,si;

void f(int c, int o, int w, int s){
    if(c<0 || o<0 || w<0 || s<0)return;
    if(v[c][o][w][s])return;
    v[c][o][w][s]=true;
    maxi=max(maxi, o);
    f(c-ci,o+oo ,w-wi, s+so);
    f(c+co,o-oi,w+wo,s-si);
}

int main(){
    freopen("C:\\Users\\sunny\\Desktop\\DATA11.txt", "r", stdin);
    for(int test=0;test<10;test++){
        memset(v,false, sizeof v);
        maxi=0;
        int c,o,w,s;cin >>c>>o>>w>>s;
        cin >>ci>>wi>>so>>oo;
        cin >>si>>oi>>co>>wo;
        f(c,o,w,s);
        printf("%d\n", maxi);
    }
}
