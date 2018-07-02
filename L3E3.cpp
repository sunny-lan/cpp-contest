//Lesson 3 excercise 3
//Sunny Lan
//2018-03-27

#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

int main() {
	int ch;
	cout << "Enter change in cents: ";
	cin >> ch;
	int mini = INT_MAX, bq, bn, bp, bd;
	for(int q = 0; q * 25 <= ch; q++)
		for(int d = 0; d * 10 + q * 25 <= ch; d++)
			for(int n = 0; n * 5 + d * 10 + q * 25 <= ch; n++)
			{
				int p = ch - (n * 5 + d * 10 + q * 25), alt = q + d + n + p;
				if(alt < mini)
					mini = alt, bq = q, bn = n, bp = p, bd = d;
			}
	cout << "quarter: " << bq << "\nnickel: " << bn << "\ndime: " << bd << "\npenny: " << bp << endl;
}
