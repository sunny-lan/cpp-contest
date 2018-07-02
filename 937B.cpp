#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll p,y;
    scanf("%lld %lld", &p, &y);
    for(ll chk=y; chk>p; chk--)
    {
        for(ll f=2; f*f<=y && f<=p; f++)
            if(chk%f==0)
                goto outer;
        printf("%lld", chk);
       return 0;
outer:
        continue;
    }
    printf("-1");
}
