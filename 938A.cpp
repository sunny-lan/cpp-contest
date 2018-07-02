#include <bits/stdc++.h>
using namespace std;

bool isv(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n>> s;
	for(int i=1;i<s.length();){
        if(isv(s[i]) && isv(s[i-1])){
            s=s.substr(0, i)+s.substr(i+1, s.length()-(i+1));
        }else
        i++;
	}
	cout <<s<<endl;
}
