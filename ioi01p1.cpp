#include <iostream>
using namespace std;
#define MAXN 1025

int arr[MAXN][MAXN];//[row][col]

int main() {
	int s;
	scanf("%d %d", &s, &s);
	while (true) {
		int op;
		scanf("%d", &op);
		switch (op) {
		case 1: {
			int x, y, a;
			scanf("%d %d %d", &x, &y, &a);
			for (int i = x + 1; i <= s; i++)
				arr[y][i] += a;
			break;
		}
		case 2: {
			int l, b, r, t, res = 0;
			scanf("%d %d %d %d", &l, &b, &r, &t);
			for (int i = b; i <= t; i++)
				res += arr[i][r + 1] - arr[i][l];
			printf("%d\n", res);
			break;
		}
		case 3: return 0;
		}
	}
}