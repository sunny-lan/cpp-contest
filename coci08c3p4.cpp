#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> pci;
#define f first
#define s second

#define MAXN 30000
#define MAXP 50

pci lt[26];

int p;
int oc[MAXP];
char tou[MAXN][MAXP];
void out(int r, int cl, int cr, char x){
    for(int i=0;i<p;i++)
        if(oc[i]>=cl && oc[i]<cr)
            tou[r][i]=x;
}
void out2(int rl, int rr, int c, char x){
    for(int i=0;i<p;i++)
        if(oc[i]==c){
            for(int j=rl;j<rr;j++)
                tou[j][i]=x;
            return;
        }
}
char dg[MAXN];
void out3(int diag, char x){
    dg[diag]=x;
    for(int i=0;i<p;i++)
        if(oc[i]==diag){
            tou[diag][i]=x;
            return;
        }
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++)
		scanf(" %c %d", &lt[i].f, &lt[i].s);

	scanf("%d", &p);
	for(int i = 0; i < p; i++)
		scanf("%d", &oc[i]), oc[i]--;

	sort(lt, lt + k);
	vector<pci> need;
	int cnt = 0;
	for(int i = k - 1; i >= 0; i--)
		if(lt[i].s % 2)
			need.push_back({lt[i].f, i}), cnt++;
	if(cnt > n)
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	int i = 0, j = 0, diag = 0;
	for(int cur = 0; cur < k; cur++) {
		if(lt[cur].s % 2) {
			out3(diag,lt[cur].f);
			diag++;
			lt[cur].s--;
			need.pop_back();
		}
		while(lt[cur].s) {
            if(i == j ) {
                    if(!dg[i]){
                int left=n-diag;
                if(left- 2 >= need.size())
                {
                    out3(diag, lt[cur].f);
                    out3(diag + 1, lt[cur].f);
                    lt[cur].s -= 2;
                    diag += 2;
                }
                    }
                j++;
            } else {
                int rm=min(lt[cur].s/2, n-j);
                out(i, j,j+rm, lt[cur].f);
                out2(j,j+rm, i, lt[cur].f);
                lt[cur].s -= rm*2;
                j+=rm;
                if(j==n)
                    j=++i;
            }
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < p; j++)
			printf("%c", tou[i][j]);
		printf("\n");
	}
}
