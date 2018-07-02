#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> sts(vector<int> l) {
    vector<int> res=l;
	bool done = false;
	while(!done) {
		done = true;
		for(int i = 0; i < l.size() - 2; i++) {
			if(res[i] > res[i + 2]) {
				done = false;
				swap(res[i], res[i + 2]);
			}
		}
	}
	return res;
}

vector<int> fts(vector<int> l) {
	vector<int> ev, od, res;
	for(int i = 0; i < l.size(); i++)
		if(i % 2)
			od.push_back(l[i]);
		else
			ev.push_back(l[i]);
	sort(ev.begin(), ev.end());
	sort(od.begin(), od.end());
	int a = 0, b = 0;
	for(int i = 0; i < l.size(); i++)
		if(i % 2)
			res.push_back(od[a]), a++;
		else
			res.push_back(ev[b]), b++;
	return res;
}

int main() {
//    while(true){
//        vector<int> st;
//        for(int i=0;i<10000;i++)
//            st.push_back(rand());
//        vector<int> ac=sts(st),wa=fts(st);
//        if(ac!=wa){
//            cout << "Error"<<endl;
//            int c;
//            cin >> c;
//        }
//        cout << "succes"<<endl;
//    }

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++) {
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		vector<int> st;
		for(int i=0;i<n;i++)
        {
            int v;cin >>v;
            st.push_back(v);
        }
        vector<int> wa=fts(st);
        sort(st.begin(), st.end());
        for(int i=0;i<n;i++){
            if(st[i]!=wa[i]){
                cout << i<<endl;
                goto outer;
            }
        }
        cout <<"OK"<<endl;
        outer:continue;
	}
}
