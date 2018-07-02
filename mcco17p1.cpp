#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int lvl[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &lvl[i]);
	priority_queue<int> crds;
	int tlvl = 0, ptr = 0, lst = 0, cnt = 0;
	while(ptr < n && tlvl < n - 1) {
		bool did = true;
		while(ptr < n && ptr <= tlvl)
			crds.push(-lvl[ptr]), ptr++, did = false;
		if(did || ptr == n)
			break;
		while(!crds.empty() && -crds.top() <= lst)
			crds.pop();
		if(crds.empty())
			break;
		tlvl += (lst = -crds.top());
		cnt++;
		crds.pop();
	}
	if(tlvl < n - 1)
		cnt = -1;
	printf("%d\n", cnt);
}
