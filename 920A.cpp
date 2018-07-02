#include <bits/stdc++.h>
using namespace std;

#define MAXN 201

bool w[MAXN];
int pos[MAXN];

int n, k;
bool g(int i) {
	if(i < 0 || i >= n)
		return true;
	return w[i];
}

void se(int i) {
	if(i < 0 || i >= n)
		return ;
	w[i] = true;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++) {
		memset(w, false, sizeof w);
		scanf("%d %d", &n, &k);
		for(int i = 0; i < k; i++)
			scanf("%d", &pos[i]), pos[i]--;
		int s, cnt = n;
		for(s = 0; cnt > 0; s++) {
			for(int i = 0; i < k; i++)
			{
				if(!g(pos[i] - s))
					cnt--;
				se(pos[i] - s);
				if(!g(pos[i] + s))
					cnt--;
				se(pos[i] + s);
			}
		}
		printf("%d\n", s);
	}
}
