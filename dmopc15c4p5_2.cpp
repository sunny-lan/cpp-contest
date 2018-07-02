#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int retA[10];
int retB[10];

inline void f(int* ret, int n) {
	int tmp= n / 10;
	for (int i = 0; i < 10; i++)
		ret[i] = tmp;

	tmp = n % 10;
	int zeroes = 0;
	for (int i = 0; i <= tmp; i++)
		ret[i]++;

	long long cp = 10;
	while (cp <= n) {
		tmp = cp*(n / (cp * 10));
		for (int i = 0; i < 10; i++)
			ret[i] += tmp;
		tmp = (n / cp) % 10;
		for (int i = 0; i < tmp; i++)
			ret[i] += cp;
		tmp = (n / cp) % 10;
		ret[tmp] += n%cp + 1;
		zeroes += min((long long)n, cp);
		cp *= 10;
	}
	ret[0] -= zeroes;
}

int main() {
	int t;
	scan( t);
	for (int i = 0; i < t; ++i) {
		int x, y;
		scan(x);
		scan(y);
		f(retA, x - 1);
		f(retB, y);
		for (int j = 0; j < 10; j++)
			printf("%d ", retB[j] - retA[j]);
		printf("\n");
	}
	return 0;
}