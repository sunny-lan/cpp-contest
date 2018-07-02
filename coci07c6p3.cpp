#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int x[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	int gc=-1;
	for(int i = 1; i < n; i++) {
		if(gc == -1)
			gc = x[i] - x[i - 1];
		else
			gc = __gcd(gc, x[i] - x[i - 1]);
	}

	printf("%d", gc);
	for(int f=2;f*f<=gc;f++)
        if(gc%f==0)
            {printf(" %d", f);
            if(gc/f!=f)printf(" %d", gc/f);
            }
}
