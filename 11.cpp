#include <iostream>
using namespace std;


int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int t;
		cin >> t;
		char** arr = new char*[t];
		for (int j = 0; j < t; j++) {
			arr[j] = new char[t];
		}
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				arr[i][j] = '.';
				if (i + j == t - 1) {
					arr[i][j] = '/';
				}
				if (i == 0 || i==t/2 || i == t-1) {
					arr[i][j] = '-';
				}
				if (j == 0 || j == t / 2 || j == t - 1) {
					arr[i][j] = '|';
				}
				if (i == j) {
					arr[i][j] = '\\';
				}

				if ((i==0 || i==t/2 || i == t-1) && (j == 0 || j == t / 2 || j == t - 1)) {
					arr[i][j] = '+';
				}
				
			}
		}
		


		arr[t / 2][t / 2] = '*';
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

