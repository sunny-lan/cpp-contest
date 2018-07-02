#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int a[MAXN];
int b[MAXN];
int v[MAXN];
int main() {
	memset(v, -1, sizeof v);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	string s;
	cin >> s;
	for(int i = 0; i < n - 1; i++)
		if(s[i] == '1')
			b[i] = 1, b[i + 1] = 2;

	int cnt = 0;
	for(int i = 0; i < n; i++) {
//            cout << "i"<<i<<endl;
		if(b[i] == 1) {
			v[a[i]] = i;
			cnt++;
		} else if(b[i] == 2) {
			v[a[i]] = i;
			for(int j = i - cnt; j <= i; j++){
//                    cout << "chek"<<j<<endl;
				if(v[j] < i - cnt || v[j] > i)
				{
					printf("NO");
					return 0;
				}}
			cnt = 0;
		} else {
			if(a[i] != i)
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
}
