#include <iostream>
#include <algorithm>
#include <climits>
#include <string>

#define MAXV 303
#define MAXP 31

using namespace std;

int dp[MAXV][MAXP];
int dp_src[MAXV][MAXP];
int dp_post[MAXV][MAXP];


int cost[MAXV][MAXV];
int post[MAXV][MAXV];

int loc[MAXV];

int dist(int x, int y) {
	return abs(loc[x] - loc[y]);
}

int main() {
	int v, c;
	cin >> v >> c;

	for (int i = 0; i < v; i++) {
		cin >> loc[i];
	}

	for (int i = 0; i < v; i++) {
		for (int j = i; j <= v; j++) {
			int sz = i + j;
			int medianA = sz / 2;

			int sumA = 0;
			for (int k = i; k < j; k++) {
				sumA += dist(k, medianA);
			}

			if (sz % 2 == 1) {
				int medianB = medianA + 1;
				int sumB = 0;
				for (int k = i; k < j; k++) {
					sumB += dist(k, medianB);
				}
				if (sumB < sumA) {
					sumA = sumB;
					medianA = medianB;
				}
			}

			cost[i][j] = sumA;
			post[i][j] = medianA;
		}
	}

	for (int i = 0; i <= c; i++) {
		dp[0][i] = 0;
		for (int j = 1; j <= v; j++) {
			dp[j][i] = 30000000;
		}
	}

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < c; j++) {
			if (dp[i][j] != 30000000)
				for (int k = i + 1; k <= v; k++) {
					int alt = dp[i][j] + cost[i][k];
					if (alt < dp[k][j + 1]) {
						dp[k][j + 1] = alt;
						dp_src[k][j + 1] = i;
						dp_post[k][j + 1] = post[i][k];
					}
				}
		}
	}

	cout << dp[v][c]<<endl;

	string out = "";
	int curr = v-1;
	for (int i = c; i > 0; i--) {
		//cout << "dp[" << curr << "," << i << "] -> " ;
		out = to_string(loc[dp_post[curr][i]]) + " " + out;
		curr = dp_src[curr][i];
		//cout << curr << endl;
	}
	cout << out << endl;

	return 0;
}