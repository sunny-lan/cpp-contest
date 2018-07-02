#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 500
#define MAXH 51
#define MAXW MAXN*MAXH

bool dp[MAXW];
int h[MAXN];
bool hh[MAXH];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}

	sort(h, h + n);

	dp[0] = true;

	for (int i = n - 2; i >= 0; i--) {
		for (int j = MAXW; j >= 0; j--)
			for (int k = h[i] + 1; k < MAXH; k++)
				if (hh[k])
				{
					int tmp = j - (k - h[i]);
					if (tmp >= 0 && dp[tmp]) {
						dp[j] = true;
						break;
					}
				}
		hh[h[i]] = true;
	}



	for (int i = 0; i <= MAXW; i++)
		if (dp[i])
			printf("%d ", i);

	printf("\n");
}