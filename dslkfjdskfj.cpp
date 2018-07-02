#include <bits/stdc++.h>
using namespace std;

#define MAXQ 100000

bool hasCar[MAXQ];

int type[MAXQ], loc[MAXQ];
int locations[MAXQ];

int main() {
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> type[i] >> loc[i];
		locations[i] = loc[i];
	}

	sort(locations, locations + q);
	unordered_map<int, int> ord;
	for(int i = 0; i < q; i++)
		ord[locations[i]] = i;

	for(int i = 0; i < q; i++) {
		int mappedLocation = ord[loc[i]];
		if(type[i] == 1) {
			hasCar[mappedLocation] = true;
		} else if(type[i] == 2) {
			hasCar[mappedLocation] = false;
		} else if(type[i] == 3) {
		    int cnt=0;
			for(int j=0;j<mappedLocation;j++)
                if(hasCar[j])
                cnt++;
            cout <<"there are: "<< cnt<<endl;
		}
	}
}
