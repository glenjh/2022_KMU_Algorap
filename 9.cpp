#include <iostream>
using namespace std;


int main() {
	int testcase;
	int muled;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		unsigned long input;
		cin >> input;
		while (input > 9) {
			unsigned long mul = 1;
			while (input != 0) {
				muled = input % 10;
				if (muled == 0) {
					muled = 1;
				}
				mul *= muled;
				input /= 10;
			}
			input = mul;
		}
		cout << input << endl;
	}
	return 0;
}