#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char *stuf[3]={"Carrots\n","Kiwis\n","Grapes\n"};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,t;scanf("%d%d%d%d",&n,&m,&k,&t);
    vector<int> waste;
    for(int i=0;i<k;i++){
        int a,b;scanf("%d%d",&a,&b);
        a--,b--;
        waste.push_back(a*m+b);
    }
    sort(waste.begin(), waste.end());
    for(int i=0;i<t;i++){
        int a,b;scanf("%d%d",&a,&b);
        a--,b--;
        int cnv=a*m+b;
        int idx=lower_bound(waste.begin(), waste.end(),cnv)-waste.begin();
        if(waste[idx]==cnv)printf("Waste\n");
        else{
            printf(stuf[(cnv-idx)%3]);
        }
    }
}

