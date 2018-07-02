#include <bits/stdc++.h>
using namespace std;

#define MAXN 4100

bitset<MAXN> str[MAXN][4];

bool dead[MAXN];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		getchar();
		for(int j = 0; j < m; j++) {
			char c = getchar();
			if(c == 'A')
				str[i][0][j] = 1;
			else if(c == 'C')
				str[i][1][j] = 1;
			else if(c == 'G')
				str[i][2][j] = 1;
			else
				str[i][3][j] = 1;
		}
		for(int j = 0; j < i; j++) {
			if(i == j)
				continue;
			int sm = 0;
			if(n > 100)
				sm = (str[i][0] ^ str[j][0]).count();
			else {
				for(int k = 0; k < 4; k++)
					sm += (str[i][k] ^ str[j][k]).count();

				sm >>= 1;
			}
			if(sm != k){
                dead[j]=true;
                dead[i]=true;
            }
		}
	}
	for(int i = 0; i < n; i++) if(!dead[i]){

		printf("%d\n", i + 1);
		return 0;
	}
}
