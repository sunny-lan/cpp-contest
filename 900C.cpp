#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int mx = -1, lst = -1, plst, msince=INT_MAX;
	int maxi = -1, best;
	for(int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		if(p > mx) {
                if(lst!=-1){
			int alt = i - lst;
			if(alt > maxi)
				maxi = alt, best = msince;
			else if(alt == maxi)
				best = min(best, msince);
                }
			msince=mx = p;

			lst = i;
		}else{
		msince=min(msince, p);
		}
	}
	int alt = n - lst;
			if(alt > maxi)
				maxi = alt, best = mx;
			else if(alt == maxi)
				best = min(best, mx);
	printf("%d\n", best);
}
