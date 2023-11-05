#include <iostream>
using namespace std;


int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int a, b, c, d;
		int co = 0;
		int sum = 0;
		cin >> a >> b >> c >> d;
		if (a < c) {
			if (d > b && c > b) {
				co = 0;
				sum = (b-a) + (d -c);
			}
			else if (b > d && b > c) {
				co = d - c;
				sum = b - a;
			}
			else if (c < b && b < d) {
				co = b - c;
				sum = d - a;
			}
			
		}
		else if (a > c) {
			if (d < b && d < a) {
				co = 0;
				sum = (b - a) + (d - c);
			}
			else if (d < b && a < d) {
				co = d - a;
				sum = b - c;
			}
			else if (a < b && b < d) {
				co = b - a;
				sum = d - c;
			}
			
		}
		cout << co << ' ' << sum << endl;
	}
	return 0;
}

