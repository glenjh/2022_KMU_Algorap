#include <iostream>
#include <vector>
using namespace std;

void print(int input) {
	int top = 0, bottom, left, right;
	int n = input;
	int printing;
	int** arr = new int* [input];
	for (int i = 0; i < input; i++) {
		arr[i] = new int[input];
	}

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			arr[i][j] = 0;
		}
	}


	if ((input / 2) % 2 == 0) {
		printing = 0;
		}
	else {
		printing = 1;
	}

	while (top < input / 2) {
		for (int i = top; i < n; i++) {
			arr[top][i] = printing;
		}
		right = top + 1;
		for (int i = right; i < n; i++) {
			arr[i][n - 1] = printing;
		}
		bottom = n - 1;
		for (int i = bottom - 1; i >= top; i--) {
			arr[n - 1][i] = printing;
		}
		left = n - 1;
		for (int i = left - 1; i > top; i--) {
			arr[i][top] = printing;
		}
		top ++;
		n --;
		printing = (printing + 1) % 2;
		//arr[input / 2][input / 2] = 0;

	}
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			cout << arr[i][j];
		}
	cout << endl;
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int t;
		cin >> t;
		print(t);
	}
	return 0;
}