#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <unordered_set>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100

string map1[MAXN];
char map[MAXN][MAXN];

unordered_set<char> players;

int main() {
	memset(map, '.', sizeof map);
	int n; cin >> n;
	ws(cin);
	for (int i = 0; i < n; i++) {
		getline(cin, map1[i]);
		for (int j = 0; j < n;j++) {
			map[i][j] = map1[i][j];
			if (map[i][j] != '.')
				players.insert(map[i][j]);
		}
	}

	char winner = '.';

	for (char p : players) {
		//row
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				bool rw = true,
					cw = true,
					diag = true,
					diag2=true;
				for (int k = 0; k < 3; k++) {
					if ( map[row][col + k] != p)
						rw = false;
					if ( map[row + k][col] != p)
						cw = false;
					if ( map[row + k][col + k] != p)
						diag = false;
					if (map[row + (3 - k)][col + k] != p)
						diag2 = false;
				}
				if (rw || cw || diag ||diag2)
				{
					winner = p;
					goto end;
				}
			}
		}
	}

end:
	if (winner == '.')
		cout << "ongoing" << endl;
	else
		cout << winner << endl;
	cin >> n;
}