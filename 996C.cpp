#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 50
#define MAXK 100

int n,k;
pii src[MAXK], dst[MAXK];
int car[4][MAXN];

vector<pair<int,pii>> moves;
void mv(int i, int r, int c){
    moves.push_back({i,{r,c}});
    car[src[i].f][src[i].s]=-1;
    src[i]={r,c};
    car[r][c]=i;
}

bool done[MAXK];


    int carsleft;

void chkcar(int i){
    if(src[i].s==dst[i].s)
        if(abs(src[i].f-dst[i].f)==1){
            if(src[i].f==1)
                mv(i, 0, dst[i].s);
            else
                mv(i, 3, dst[i].s);
                done[i]=true;
                carsleft--;
        }
}

pii computeNext(pii cur){
    if(cur.f==1){
        if(cur.s==n-1){
            return {2, n-1};
        }
        return {1, cur.s+1};
    }else{
        if(cur.s==0){
            return {1, 0};
        }
        return {2, cur.s-1};
    }
}

int main(){
    memset(car, -1, sizeof car);

    scanf("%d %d", &n, &k);
    for(int r=0;r<4;r++){
        for(int c=0;c<n;c++){
            int nm;scanf("%d", &nm);nm--;
            if(r==1 || r==2){
                src[nm]={r,c};
                car[r][c]=nm;
            }else{
                dst[nm]={r,c};
            }
        }
    }


    carsleft=k;
    //check all direct
    for(int i=0;i<k;i++){
        chkcar(i);
    }

    //keep on looping
    while(carsleft>0){
        int movement=0;
        for(int i=0;i<k;i++)if(!done[i]){
            while(true){
                pii nxt=computeNext(src[i]);
                if(car[nxt.f][nxt.s]==-1){
                    mv(i, nxt.f, nxt.s);
    movement++;
                    chkcar(i);
                    if(done[i])break;
                }else{
                    break;
                }
            }
        }
        if(movement==0){
            printf("-1\n");
            return 0;
        }
    }

    if(moves.size()>20000)
        printf("-1\n");
    else{
        printf("%d\n", moves.size());
        for(auto kek:moves){
            printf("%d %d %d\n", kek.f+1, kek.s.f+1, kek.s.s+1);
        }
    }
}
