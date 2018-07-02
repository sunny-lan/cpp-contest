#include <iostream>

using namespace std;

#define MAXN 5010

int f[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &f[i]);
    for(int i=1; i<=n; i++)
    {
        if(f[f[f[i]]]==i)
        {
            printf("YES");
            goto stop;
        }
    }
    printf("NO");
stop:
    cin >>n;
}
