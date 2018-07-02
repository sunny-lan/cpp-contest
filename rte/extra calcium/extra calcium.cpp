#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXE 1000000000
#define MAXN 1000000

int n;
int d[MAXN], e[MAXN];

double ac(){
    double maxi=0;
    for(int i=0;i<1<<n;i++){
        ll num=0, den=0;
        for(int j=0;j<n;j++)
        if((i>>j)&1){
            num+=e[j];
            den+=d[j];
        }
        maxi=max(maxi, num/(double)den);
    }
    return maxi;
}

double wa(){
    double maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi, e[i]/(double)d[i]);
    }
    return maxi;
}

void gen2(){
    n=2;
    while(1){
        for(int i=0;i<n;i++)
            e[i]=rand()%MAXE+1, d[i]=rand()%MAXE+1;
        if(ac()!=wa())
            break;
    }
}

void gen(){
    int n=10;
    for(int t=0;t<20;t++){
        ofstream in("dat/"+to_string(t)+".in");
        in << n<<endl;
        for(int i=0;i<n;i++){
            int ei=rand()%MAXE+1, di=rand()%MAXE+1;
            in<<ei<<" "<<di<<endl;
        }
        n=min(MAXN, 4*n);
    }
}

void dostuf(){
    for(int t=0;t<20;t++){
        ifstream in("dat/"+to_string(t)+".in");
        ofstream out("dat/"+to_string(t)+".out");
        in >>n;
        for(int i=0;i<n;i++)
            in >>e[i]>>d[i];
        out<<setprecision(9)<<wa()<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    dostuf();
//gen2();
}
