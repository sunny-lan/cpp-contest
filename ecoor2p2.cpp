#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

typedef pair<int, double> pid;
#define f first
#define s second

pid a[MAXN];

int main(){
    freopen("C:\\Users\\sunny\\Desktop\\DATA21.txt", "r", stdin);
    for(int test=0;test<10;test++){
        int n;scanf("%d", &n);
        for(int i=0;i<n;i++)
            scanf("%d %lf", &a[i].f, &a[i].s);
        sort(a, a+n);
        priority_queue<double, vector<double>, greater<double>> q;
        for(int i=0;i<n;i++){
            if(q.size()<a[i].f){
                q.push(a[i].s);
                continue;
            }
            if(q.top()<a[i].s)
                q.pop();
            else
                continue;
            q.push(a[i].s);
        }
        double tot=0;
        while(!q.empty())
            tot+=q.top(), q.pop();
        printf("%.4lf\n", tot);
    }
}
