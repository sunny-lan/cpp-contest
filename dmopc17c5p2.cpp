#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int psa[2][MAXN];

int main() {
	string s;cin >>s;
	int n=s.length();
	for(int i=0;i<n;i++)
        psa[s[i]-'0'][i+1]++,
        psa[0][i+1]+=psa[0][i],
        psa[1][i+1]+=psa[1][i];
//        for(int i=0;i<=n;i++)
//            cout << psa[0][i]<< " ";
//        cout <<endl;
//        for(int i=0;i<=n;i++)
//            cout << psa[1][i]<< " ";
//        cout <<endl;
    int q;cin >>q;
    for(int i=0;i<q;i++){
        int x,y,z;cin >>x>>y>>z;
        x--;
        int loc=lower_bound(psa[z]+x, psa[z]+n+1, y+psa[z][x])-psa[z];
        if(psa[z][loc]-psa[z][x]==y)
            printf("%d\n", loc);
        else
            printf("-1\n");
    }
}
