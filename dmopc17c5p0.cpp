#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, p;
	string v;
	cin >> b >> p >> v;
	if(v == "Y") {
		if(p * 5 <= b)
			printf("B");
		else if(p * 2 <= b)
			printf("D");
		else
			printf("NO PIZZA");
	} else {
		if(p * 5 <= b)
		printf("A");
		else if(p * 2 <= b)
			printf("C");
		else
			printf("NO PIZZA");
	}

}
