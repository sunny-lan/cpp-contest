#include <bits/stdc++.h>
using namespace std;

int a[200];

int main(){
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        int aa;
        for(int j=i+1;j<n;j++)
        if(a[j]==a[i]){
            aa=j;
            break;
        }
        cout << "dst "<<aa<<endl;

        for(;aa>i+1;aa--){
            swap(a[aa], a[aa-1]);
            cnt++;
        }
    }

    printf("%d\n", cnt);
}
