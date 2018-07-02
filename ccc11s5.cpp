#include <iostream>
#include <queue>

using namespace std;

#define MAXN 25

queue<int> toExpand;
queue<int> count1;

bool visited[1 << MAXN];

int main() {
	int k;
	cin >> k;
	int baseState = 0;
	for (int digit = 0; digit < k; digit++) {
		int j;
		cin >> j;
		if (j == 1)
			baseState |= 1 << digit;
	}

	toExpand.push(baseState);
	count1.push(0);
	while (!toExpand.empty()) {
		int currentState = toExpand.front();
		toExpand.pop();
		int currentCount = count1.front();
		count1.pop();

		if (visited[currentState])
			continue;

		int consecCount = 0;
		int startIdx = -1;
		for (int digitIdx = 0; digitIdx < k; digitIdx++) {
			bool digit = (1 & (currentState >> digitIdx)) == 1;
			if (digit) {
				consecCount++;
				if (startIdx == -1)
					startIdx = digitIdx;
			}
			else {
				if (consecCount >= 4) {
					for (int idx = startIdx; idx < digitIdx; idx++) {
						currentState ^= 1 << idx;
					}
				}
				consecCount = 0;

				startIdx = -1;
			}
		}
		if (consecCount >= 4) {
			for (int idx = startIdx; idx < k; idx++) {
				currentState ^= 1 << idx;
			}
		}

		if (visited[currentState])
			continue;

		if (currentState == 0) {
			cout << currentCount<<endl;
			break;
		}

		for (int digitIdx = 0; digitIdx < k; digitIdx++) {
			if (((currentState >> digitIdx) & 1) != 1) {
				int next = currentState | (1 << digitIdx);
				if (!visited[next]) {
					toExpand.push(next);
					count1.push(currentCount + 1);
				}
			}
		}

		visited[currentState] = true;
	}
}