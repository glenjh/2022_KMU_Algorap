#include <iostream>
using namespace std;


int main() {
	int testcases;
	cin >> testcases;

	for (int i = 0; i < testcases; i++) {
		int test;
		int data;
		int before = 101;
		int top = 0;
		int cnt = 0;
		cin >> test;
		for (int j = 0; j < test; j++) {
			cin >>data;
			if (data > before) {
				top = data;
			}
			if (data < top) {
				cnt++;
				top = 0;
			}
			before = data;
		}
		cout << cnt << endl;
	}
	return 0;
}

