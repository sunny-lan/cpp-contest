#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

typedef unsigned long long ull;

#define MAX 4294967291ull

constexpr char16_t const * esc = u"\0\"\\\a\b\f\n\r\t\v\x7F";
const string esc2[] = { "\\0", "\\\"","\\\\", "\\a","\\b", "\\f","\\n", "\\r", "\\t", "\\v", "\\x7F"};
const int cnt = 10;

inline void escape(char16_t tmp) {
	for (int i = 0; i < cnt; i++) {
		if (esc[i] == tmp) {
			cout << esc2[i];
			return;
		}
	}
}

inline void disp(ull t) {
	printf("\\u%04X", t);
}

int main() {
	int op;
	while (true) {
		cout << "Please enter op: ";
		cin >> op;
		if (op == 1) {
			ofstream myfile;
			myfile.open("factorial.txt");
			ull curr = 1ULL;
			for (ull i = 1ULL; i <= MAX; i++) {
				curr = (curr*i) % MAX;

				if (i % 1000ULL == 1ULL) {
					myfile << curr << endl;
				}

				if (i % 1000000ULL == 2ULL)
					cout << "Progress: " << i << endl;
			}
		}
		else if (op == 2) {
			ull spacing;
			cout << "Please enter spacing: ";
			cin >> spacing;
			++spacing;
			ifstream myfile("factorial.txt");
			for (ull i = 0ull; ; ++i) {
				if (i%spacing == 0ull) {
					ull n;
					if (!(myfile >> n))
						break;
					ull a = n >> 16ull;
					ull b = n % 65536ull;
					disp(a);
					disp(b);
				}
				else {
					if (!myfile.ignore(numeric_limits<streamsize>::max(), myfile.widen('\n'))) {
						break;
					}
				}
			}
		}
		else if (op == 3) {
			ull x;
			cout << "Please enter number to factorial: ";
			cin >> x;
			ull curr = 1ULL;
			for (ull y = 1ULL; y <= x; y++) {
				if ((y&((1 << 25) - 1)) == 0)
					cout << "Progress: " << y << endl;
				curr = (curr*y) % MAX;
			}
			cout << curr << endl;
		}
		else if(op==3){
			ull z;
			cout << "Please enter number to scan for: ";
			cin >> z;
			ull curr = 1ULL;
			for (ull y = 1ULL; y <= MAX; y++) {
				if ((y&((1 << 25) - 1)) == 0)
					cout << "Progress: " << y << endl;
				curr = (curr*y) % MAX;
				if (curr == z)
				{
					cout << "SUCESS" << endl;
					break;
				}
			}
		}
		else if(op==4) {
			ull z;
			cout << "Please enter number to convert: ";
			cin >> z;
			ull a = z >> 16ull;
			ull b = z % 65536ull;
			disp(a);
			disp(b);
			cout << endl;
		}

	}
}