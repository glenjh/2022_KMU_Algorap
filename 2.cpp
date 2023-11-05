#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int testdata;
	cin >> testdata;
	for (int i = 0; i < testdata; i++) {
		vector<int> v;
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		cout << v[v.size() - 1] << ' ' << v[0] << '\n';
	}
	return 0;
}