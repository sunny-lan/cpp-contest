#include <bits/stdc++.h>
using namespace std;
#include "testrig.h"
#include "correct.h"
#include "tested.h"

pii test_cross(int cases) {
	printf("Cross product: ");
	int ac = 0;
	for(int i = 0; i < cases; i++) {
		vec a = {randdouble(), randdouble()},
			b = {randdouble(), randdouble()};
        auto acr=correct::cross(a, b), war=tested::cross(a, b);
		if(acr == war)
			ac++;
	}
	pii res = {ac, cases};
	printf("%d/%d\n", res);
	return res;
}

int main()
{
	test_cross(100);
	return 0;
}
