#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 50
#define MAXK 100

int src[MAXK];
int dst[MAXK];

int main(){
    srand(time(0));
   for(int i=1;i<=99;i++)
    src[i]=dst[i]=i;
   random_shuffle(src, src+MAXK);
   random_shuffle(dst, dst+MAXK);

   for(int i=0;i<50;i++)
    printf("%d ", dst[i]);
    printf("\n");
   for(int i=0;i<50;i++)
    printf("%d ", src[i]);
    printf("\n");
   for(int i=50;i<100;i++)
    printf("%d ", src[i]);
    printf("\n");
for(int i=50;i<100;i++)
    printf("%d ", dst[i]);
    printf("\n");
}
