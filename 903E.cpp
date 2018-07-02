#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001

string kust[MAXN];

int cmp_slow(const string &a, const string &b) {
	int cnt = 0;
	for(int i = 0; i < a.length(); i++)
		if(a[i] != b[i])
			cnt++;
	return cnt;
}

int dp[MAXN];
 bool flg=false;
int cmp_fst(int idx, int i, int j) {
	int before = 0;
	if(kust[0][i] != kust[idx][i])
		before++;
	if(kust[0][j] != kust[idx][j])
		before++;
	int after = 0;
	if(kust[0][j] != kust[idx][i])
		after++;
	if(kust[0][i] != kust[idx][j])
		after++;

//	if(kust[0][i] != kust[0][j])
//		if(kust[idx][i] != kust[idx][j])
			if(!flg && dp[idx] == 2 && before == 2 && after == 0){
//    cout << "   v "<<kust[0]<<" "<<kust[idx]<<endl;
//    cout << "   v "<<kust[0][j]<<" "<<kust[idx][i]<<endl;
//    cout << "   v "<<kust[0][i]<< " "<<kust[idx][j]<<endl;
//    cout << "   before "<<before<< "aft"<<after<<endl;
				return 3;
			}
//
	return dp[idx] + (after - before);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n;
	cin >> k >> n;
	for(int i = 0; i < k; i++)
		cin >> kust[i];
	unordered_map<char, int> orig;

	for(char c : kust[0]){
		orig[c]++;
		if(orig[c]>1)flg=true;
	}
	for(int i = 1; i < k; i++) {
		dp[i] = cmp_slow(kust[0], kust[i]);

		unordered_map<char, int> cur;
		for(char c : kust[i])
			cur[c]++;
		for(char c = 'a'; c <= 'z'; c++)
			if(cur[c] != orig[c])
			{

				cout << -1 << endl;
				return 0;
			}
//		cout <<kust[0]<<" vs "<<kust[i]<< " = "<<dp[i]<<endl;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
//            cout << "swp "<<i<<" "<<j<<endl;
			for(int l = 1; l < k; l++) {
//				cout << " cmp " << kust[l]<<endl;
				int alt = cmp_fst(l, i, j);
//				cout << " = " << alt << endl;
				if(alt != 0 && alt != 2)
					goto outer;
			}
			swap(kust[0][i], kust[0][j]);
			cout << kust[0] << endl;
			return 0;
		outer:
			continue;
		}
	}
	cout << -1 << endl;
}
