#include <bits/stdc++.h>
using namespace std;

int seq[20];
bool aa[20];

int main(){
    int n,m;cin >>n>>m;
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    for(int i=0;i<m;i++){
        int b;cin >>b;
        aa[b]=true;
    }
    for(int i=0;i<n;i++){
        if(aa[seq[i]])
            cout << seq[i]<<" ";
    }
}
