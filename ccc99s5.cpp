#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int map[26],aa[21],ba[21],ca[21];
char res[21];

int main() {
	int n; cin >> n;
	for (int j = 0; j < n; j++) {
		int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
		memset(map, -1, sizeof map);
		memset(aa, -1, sizeof aa), memset(ba, -1, sizeof ba), memset(ca, -1, sizeof ca);
		string a, b, c; cin >> a >> b >> c;
		int al = a.length(), bl = b.length(), cl = c.length();
		int idx = 0;
		for (int i = 0; i < al; i++) {
			if (map[a[i] - 'A'] == -1) map[a[i] - 'A'] = idx++;
			aa[al - i - 1] = map[a[i] - 'A'];
		}
		for (int i = 0; i < bl; i++) {
			if (map[b[i] - 'A'] == -1) map[b[i] - 'A'] = idx++;
			ba[bl - i - 1] = map[b[i] - 'A'];
		}
		for (int i = 0; i < cl; i++) {
			if (map[c[i] - 'A'] == -1) map[c[i] - 'A'] = idx++;
			ca[cl - i - 1] = map[c[i] - 'A'];
		}
		do {
			if (arr[aa[al - 1]] == 0)continue;
			if (arr[ba[bl - 1]] == 0)continue;
			int cry = 0;
			for (int i = 0; i < cl; i++) {
				int s = (aa[i] == -1 ? 0 : arr[aa[i]]) + (ba[i] == -1 ? 0 : arr[ba[i]]) + cry;
				if (i == cl - 1 && s == 0)goto next;
				res[cl - i - 1] = (s % 10) + '0';
				if (s % 10 != arr[ca[i]])goto next;
				cry = s / 10;
			}
			res[cl] = 0;
			for (int i = al - 1; i >= 0; i--)
				printf("%d", arr[aa[i]]);
			printf("\n");
			for (int i = bl - 1; i >= 0; i--)
				printf("%d", arr[ba[i]]);
			printf("\n%s\n", res);
			break;
		next:continue;
		} while (next_permutation(arr, arr + 10));
	}
}