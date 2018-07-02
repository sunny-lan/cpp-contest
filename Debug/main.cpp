#include <bits/stdc++.h>
using namespace std;

int a[200];
bool v[200];


int main(){
    int n; scanf("%d", &n);
    for(int i=0;i<n*2;i++){
        scanf("%d", &a[i]);
    }

    int cnt=0;
    for(int i=0;i<n*2;i+=2){
        int aa;
        for(int j=i+1;j<n*2;j++)
        if(a[j]==a[i]){
            aa=j;
            break;
        }

        for(;aa>i+1;aa--){
            swap(a[aa], a[aa-1]);
            cnt++;
        }
    }

    printf("%d\n", cnt);
}
