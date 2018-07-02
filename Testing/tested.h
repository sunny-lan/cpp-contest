#include "testrig.h"
#include <bits/stdc++.h>
using namespace std;


namespace tested {
double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}
}
