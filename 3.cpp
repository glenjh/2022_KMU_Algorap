#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	float h_move = 0.5;
	float m_move = 6.0;
	float rel;

	for (int i = 0; i < testcase; i++) {
		float h, m;
		cin >> h >> m;
		rel = abs((h*60 + m) * h_move - m * m_move);
		if (rel <= 180) {
			cout << int(rel) << endl;
		}
		else if(180 < rel){
			cout << int(360 - rel) << endl;
		}
	}
	return 0;
}