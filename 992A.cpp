#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d", &n);
    unordered_set<int> kek;
    for(int i=0;i<n;i++)
    {

        int b;scanf("%d", &b);
        kek.insert(b);

    }
    kek.erase(0);
    printf("%d\n", kek.size());
}
