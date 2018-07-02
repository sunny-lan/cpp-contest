#include <iostream>

using namespace std;

float sign(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y)
{
	return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

bool PointInTriangle(int ptx, int pty, int v1x, int v1y, int v2x, int v2y, int v3x, int v3y)
{
	bool b1, b2, b3;

	b1 = sign(ptx, pty, v1x, v1y, v2x, v2y) < 0;
	b2 = sign(ptx, pty, v2x, v2y, v3x, v3y) < 0;
	b3 = sign(ptx, pty, v3x, v3y, v1x, v1y) < 0;

	return ((b1 == b2) && (b2 == b3));
}

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {

	}
}