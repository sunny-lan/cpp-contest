#include <bits/stdc++.h>
using namespace std;

#define MAXN 10

string mp[MAXN];
int sz[MAXN];
int m, n, s;
int ind=0;
bool f(int i);
bool g(int i){
//        for(int j=0;j<ind;j++)
//            cout <<" ";
//            cout << i<<endl;
//    for(int i=0;i<m;i++)
//    {
//        for(int j=0;j<ind;j++)
//            cout <<" ";
//        cout << mp[i]<<endl;
//    }
      ind++;
      bool res=f(i);
      ind--;
      return res;
}

bool f(int i) {
	if(i == s)
		return true;
	for(int x = 0; x < m; x++)
		for(int y = 0; y < n; y++)
			if(mp[x][y] == '0') {
//        for(int j=0;j<ind;j++)
//            cout <<" ";
//                cout << "st "<<x<< " "<<y<<endl;
				if(x + sz[i] < m) {
					int cur = x;
					bool cancer=false;
					for(; cur < x + sz[i]; cur++) {
						if(mp[cur][y] > '0')
                                cancer=true;
						mp[cur][y] ++;
					}
					if(!cancer && cur == x + sz[i])
						if( g(i + 1))
							return true;
					for(cur=x+sz[i]-1; cur >= x; cur--)
						mp[cur][y] --;
				}
				if(y + sz[i] < n) {
					int cur = y;
					bool cancer=false;
					for(; cur < y + sz[i]; cur++) {
						if(mp[x][cur]>'0')
                                cancer=true;
						mp[x][cur]++;
					}
					if(!cancer && cur == y + sz[i])
						if(g(i + 1))
							return true;
					for(cur=y+sz[i]-1; cur >= y; cur--)
						mp[x][cur] --;
				}
			}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> s;
	for(int i = 0; i < s; i++)
		cin >> sz[i];
	for(int i = 0; i < m; i++)
		cin >> mp[i];
	printf(g(0) ? "yes" : "no");
}
