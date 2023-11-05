#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int n;
		int top, bottom, left, right;
		top = 0;
		int start, end;
		cin >> n >> start >> end;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		int n_2 = n;
		int cnt = n*n;
		int** arr = new int*[n];
		vector<int> v;
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = i*n + j+1;
			}
		}
		while (cnt > 0) {
			//top = 0;
			for (int i = top; i < n_2; i++) {
				//cout << arr[top][i] << ' ';
				v.push_back(arr[top][i]);
				cnt--;
			}
			right = top + 1;
			for (int i = right; i < n_2; i++) {
				//cout << arr[i][n_2 - 1] << ' ';
				v.push_back(arr[i][n_2-1]);
				cnt--;
			}
			bottom = n_2 - 1;
			for (int i = bottom-1; i >= top; i--) {
				//cout << arr[n_2 - 1][i] << ' ';
				v.push_back(arr[n_2-1][i]);
				cnt--;
			}
			left = n_2 - 1;
			for (int i = left-1; i > top; i--) {
				//cout << arr[i][top] << ' ';
				v.push_back(arr[i][top]);
				cnt--;
			}
			top++;
			n_2--;
		}
		if (end == start) {
			cout << v[start] << endl;
		}
		else {
			for (int i = start-1; i < end; i++) {
				cout << v[i] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}