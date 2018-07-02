#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int t=0;t<10;t++){
        int m=150;
        if(t>5)
        m=1e9;
        int a=rand()%m,b=rand()%m, c=rand()%m;
        ofstream in("dat/"+to_string(t)+".in"), out("dat/"+to_string(t)+".out");
        in <<a<<" "<<b<<" "<<c<<endl;
        out<< max(0,101-min(a,min(b,c)))<<endl;
    }
}
