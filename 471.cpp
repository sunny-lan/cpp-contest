#include <bits/stdc++.h>
using namespace std;

void mian() {
	int n;
	scanf("%d", &n);
    if(n==1)
        printf("-1/1");
    else if(n==2)
        printf("0/1");
    else{
        int rr=-(n-2);
        rr+=2;

    }
}

int main() {
	while(!feof(stdin))
        printf("Case #%d: "),
		mian(),
		printf("\n");
}
