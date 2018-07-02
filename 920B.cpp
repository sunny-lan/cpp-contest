#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++) {
		int n;
		scanf("%d", &n);
		int time = 1;
		for(int i = 0; i < n; i++) {
			int l, r;
			scanf("%d %d", &l, &r);
			int alt = max(time , l);
			if(alt>r) {
				printf("0 ");
				continue;
			}
			printf("%d ", alt);
			time = alt+1;
		}
		printf("\n");
	}
}
