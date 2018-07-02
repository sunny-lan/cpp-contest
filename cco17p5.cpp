#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<pair<int, int>> people;
priority_queue<int, vector<int>, greater<int>> mayBuy;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	int cost = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0 || b == 0)
			cnt++;
		else if (a >= n)
			cnt++, cost += b;
		else
			people.push_back({ a, b });
	}

	sort(people.begin(), people.end(), cmp);

	int n2 = people.size();

	for (int i = 0; i < n2; i++) {
		if (people[i].first <= cnt + (n2 - i -1)) {
			mayBuy.push(people[i].second);
		}
		else {
			int next;
			if (mayBuy.size() == 0 || people[i].second < (next = mayBuy.top())) {
				cost += people[i].second;
			}
			else {
				cost += next;
				mayBuy.pop();
				mayBuy.push(people[i].second);
			}
			cnt++;
		}
	}
	cout << cost << endl;
	cin >> n;
}