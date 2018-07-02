#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 101

int v[MAXN][MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &v[i][j]);
	}

	int uplef = v[0][0],
		uprigh=v[0][n-1],
		botlef=v[n-1][0],
		botrigh=v[n-1][n-1];

	pair<int, string> ar[] = { {uplef, "UL"} , {uprigh, "UR"}, {botlef, "BL"}, {botrigh, "BR"} };
	sort(ar, ar + 4);

	if (ar[0].second == "UL" && ar[3].second == "BR") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%d ", v[i][j]);
			printf("\n");
		}
	}
	if (ar[0].second == "UR" && ar[3].second == "BL") {
		for (int col = n - 1; col >= 0; col--) {
			for (int row = 0; row < n; row++) {
				printf("%d ", v[row][col]);
			}
			printf("\n");
		}
	}
	if (ar[0].second == "BR" && ar[3].second == "UL") {
		for (int row = n - 1; row >= 0; row--) {
			for (int col = n-1; col >=0; col--) {
				printf("%d ", v[row][col]);
			}
			printf("\n");
		}
	}
	if (ar[0].second == "BL" && ar[3].second == "UR") {
		for (int col = 0; col < n;col++) {
			for (int row = n - 1; row >= 0; row--) {
				printf("%d ", v[row][col]);
			}
			printf("\n");
		}
	}
	cin >> n;
}