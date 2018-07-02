#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 201

int dp[MAXN][MAXN];

int f(int i, int j) {
	int res = dp[i][j];
	if (res == -1) {
		for (int k = i + 1; k < j; k++) {
			int sum = dp[i][i] + dp[k][k] + dp[j][j];
			//transition based on this:
			//if you have three numbers that add up, 
			//you must have removed all the numbers in between
			res = max(res, f(i,k) + sum + f(k,j));
		}
		dp[i][j] = res;
	}
	return res;
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++)
			cin >> dp[i][i];

		//base case - if there are only two numbers, you cannot remove anything
		for (int i = 0; i < n - 1; i++) {
			dp[i][i + 1] = 0;
		}

		cout << f(0, n - 1) << endl;
	}
}