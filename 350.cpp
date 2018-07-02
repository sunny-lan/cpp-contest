#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

unordered_map<int,int> v;

int b[MAXN];

int main(){
    srand(time(0));

    int m;scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &b[i]);
        v[b[i]]++;
    }

    int a1=rand()%+666;
    int cur=b[0];
    v[b[0]]--;
    printf("%d %d", a1, cur^a1);
    while(1){
        int nxt=-1;
        for(int i=0;i<m;i++){
            if(v[b[i]]==0)continue;
            if(v[cur^b[i]]>0){
                if(v[b[0]^b[i]]>0)
                    nxt=b[i];
                else
                    nxt=cur^b[i];
                break;
            }
        }
        if(nxt==-1)break;
        v[nxt]--;
        v[cur^nxt]--;
        cur=nxt;
        printf(" %d", cur^a1);
    }
    printf("\n");
}
