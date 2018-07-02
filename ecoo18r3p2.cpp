#include <bits/stdc++.h>
using namespace std;
const int base = 26;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second
const int N = 100005;
string wrd[N];
string msg, nw,str;

ll ans=1LL<<60;

ll dp[N];
int n;

bool chk(int a, int b) {
	if(a + wrd[b].size() > nw.size())
		return 0;
	for(int i = a, j = 0; j < wrd[b].size(); ++i, ++j)
		if(nw[i] != wrd[b][j])
			return 0;
	return 1;
}

ll g(int i) {
	if(i == nw.size())
		return 1;

	ll &res=dp[i];
	if(res>=0x3f3f3f3f3f3f3f3f){
        for(int j = 0; j < n; ++j)
            if(chk(i, j))
                res = min(res, g(i + wrd[j].size())+
                 wrd[j].size()*wrd[j].size());
	}
    return res;
}

void f(int idx) {
	memset(dp, 0x3f, sizeof dp);
	nw.clear();
	for(int i = 0, j = 0; i < msg.size(); ++i, j = (j + 1) % wrd[idx].size()) {
		int a = msg[i] - 'A', b = wrd[idx][j] - 'A';
		char cur = (a - b + base-1) % base + 'A';
		nw.push_back(cur);
	}
//	cout<<nw<<" "<<wrd[idx]<<endl;
    ll tmp= g(0);
    if(tmp<ans){
        str=nw ,ans=tmp;
    }else if(tmp==ans){
        if(nw<str)
            str=nw;
    }

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("C:\\Users\\Sunny\\Desktop\\DATA21.txt", "r", stdin);
	for(int tst = 0; tst < 10; ++tst) {
        cin>>n;
		for(int i = 0; i < n; ++i)
			cin >> wrd[i];
		cin >> msg;
		ans=1LL<<60;
		for(int i = 0; i < n; ++i) {
            f(i);
		}
//        cout<<str<<endl;
		for(int i=0;i<10;++i)
            cout<<str[i];
        cout<<" "<<ans-1<<endl;
	}
	return 0;
}
