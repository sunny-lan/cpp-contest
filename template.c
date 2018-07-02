#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second

#define MAXN 2000000

bool v[MAXN];
int kust[MAXN];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<pii> evt;
    for(int i=0;i<k;i++){
        int idx;scanf("%d", &idx);
        evt.push_back({idx, 1});
    }
    for(int i=0;i<k+1;i++){
        int idx;scanf("%d", &idx);
        evt.push_back({idx, 0});
        kust[idx]=i;
    }
    sort(evt.begin(), evt.end());
    int i=0;
    stack<int> stu;
    int cnt=0;
    while(1){
        if(!v[i]){
            if(evt[i].s==0)
                stu.push(evt[i].f),
            v[i]=true;
            else
            {
                if(!stu.empty())
                    stu.pop(), cnt++, v[i]=true;
                if(cnt==k)break;
            }
        }
        i++;
       if(i==evt.size())
       i=0;
    }
    printf("%d\n", stu.top());
    return 0;
}
