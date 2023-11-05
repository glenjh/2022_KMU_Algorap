#include <iostream>
using namespace std;

int main() {
	int testdata;
	cin >> testdata;
	for (int i = 0; i < testdata; i++) {
		int mul = 1;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			mul *= input%10;
			mul = mul % 10;
		}
		cout << mul<< endl;
	}
	return 0;
}