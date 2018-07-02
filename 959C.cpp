#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	if(n < 6) {
		printf("-1\n");
	}else{
	printf("1 2\n");
	printf("1 3\n");
	printf("1 4\n");
	printf("2 5\n");
	printf("2 6\n");
	for(int i = 7; i <= n; i++)
		printf("1 %d\n", i);
	}
	for(int i = 2; i <= n; i++) {
		printf("1 %d\n", i);
	}
}
