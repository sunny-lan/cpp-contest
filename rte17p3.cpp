#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
string essay[100001];
vector<int> word;
vector<int> inator;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	//fstream of;
	//of.open("s2c1.in");

	for (int i = 0; i < n; ++i)
		cin >> essay[i], word.push_back(i), inator.push_back(0);

	for (int i = 0; i < q; ++i) {
		int cmd, a, b;
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b;
			swap(word[--a], word[--b]);
		}
		else {
			cin >> a;
			word.push_back(word[--a]);
			inator.push_back(inator[a] + 1);
		}
	}
	for (int i = 0; i < word.size(); ++i) {
		cout << essay[word[i]];
		for (int j = 0; j < inator[i]; ++j)
			cout << "inator";
		cout << " ";
	}
	cout << "\n";
	return 0;
}