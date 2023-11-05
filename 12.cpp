#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int p1x, p1y, q1x, q1y;
		int p2x, p2y, q2x, q2y;
		cin >> p1x >> p1y >> q1x >> q1y;
		cin >> p2x >> p2y >> q2x >> q2y;

		int width;
		int len;


		if ((p1y > q2y) || (p2y > q1y) || (p1x > q2x) || (p2x > q1x)) { // 안겹칠때
			len = 2 * (abs(q1x - p1x) + abs(q1y - p1y) + abs(q2x - p2x) + abs(q2y - p2y));
			width = (abs(q1x - p1x) * abs(q1y - p1y)) + (abs(q2x - p2x) * abs(q2y - p2y));
		}
		else { //겹칠때
			int x, y, ux, uy; // 순서대로 겹치는 구간의 왼쪽 하단 좌표, 우측 상단좌표
			if (p1x > p2x) { //x
				x = p1x;
			}
			else {
				x = p2x;
			}

			if (p1y > p2y) { //y
				y = p1y;
			}
			else {
				y = p2y;
			}

			if (q1x > q2x) { //ux
				ux = q2x;
			}
			else {
				ux = q1x;
			}

			if (q1y > q2y) { // uy
				uy = q2y;
			}
			else {
				uy = q1y;
			}
			len = 2 * (abs(q1x - p1x) + abs(q1y - p1y) + abs(q2x - p2x) + abs(q2y - p2y)) - 2*(abs(ux - x) + abs(uy -y));
			width = (abs(q1x - p1x) * abs(q1y - p1y)) + (abs(q2x - p2x) * abs(q2y - p2y)) - (abs(ux - x) * abs(uy -y));
		}
		cout << width << ' ' << len << endl;
	}
	return 0;
}

