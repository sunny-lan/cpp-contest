#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c[1000010];

ll f(int i){
   ll res=c[i];
    if(i-2>=0)
        res=max(res, c[i-1]+f(i-2));
//        if(i-1>=0)
//        res=max(res, f(i-1))
    return res;
}

int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &c[i]);

	if(k > n + 1){
		printf("-1\n");
	}else {
	    if(k==1 && n>=2){
         printf("%lld", max(c[0], c[1]));
        }else{
    	    printf("%lld\n", f(k-1));
    	}
    }
}
