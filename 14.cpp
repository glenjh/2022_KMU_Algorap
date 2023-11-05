#include <iostream>
using namespace std;

const int G = 1582;
int main() {
	int testcase;
    cin >> testcase;
    for(int i=0;i<testcase;i++){
        int y, m, d;
        unsigned long long int days = 0;
        int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        cin >> y >> m >> d;
        for(int j=G; j < y;j++){
            if( (j % 400 == 0) || (j % 100 != 0  && j % 4 == 0)){
                days += 366;
            }else{
                days += 365;
            }
        }
        if( (y % 400 == 0) || (y % 100 != 0  && y % 4 == 0)){
            day[1] = 29;
            for(int j=0;j<m-1;j++){
                days = (days+ day[j]);
            }
        }else{
            for(int j=0;j<m-1;j++){
                days = (days+ day[j]);
            }
        }
        
        days += (d -1);
        days = days%7;
        cout << (days+5) % 7 << endl;
    }
	return 0;
}

