#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
	freopen("C:\\Users\\Sunny\\Desktop\\DATA21.txt", "r", stdin);
	for(int testcase = 0; testcase < 10; testcase++) {
		int n;
		cin >> n;
		vector<int> cancer;
		int mini = INT_MAX;
		for(int i = 0; i < n; i++) {
			int id, m;
			cin >> id >> m;
			int cmini = INT_MAX;
			for(int j = 0; j < m; j++) {
				int val;
				cin >> val;
				cmini = min(cmini, val);
			}
			if(cmini < mini) {
				mini = cmini;
				cancer.clear();
			}
			if(cmini == mini)
			{
				cancer.push_back(id);
			}
		}

		sort(cancer.begin(),cancer.end());

		cout << mini << " {";
		for(int j = 0; j < cancer.size(); j++)
		{
			cout << cancer[j];
			if(j != cancer.size() - 1)
				cout << ",";
		}
		cout << "}" << endl;
	}
}
