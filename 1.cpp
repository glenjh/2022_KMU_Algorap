#include <iostream>
using namespace std;


int main(void){
    int testnum;

    cin >> testnum;
    for(int i=0;i<testnum;i++){
        int numdate, data;
        int sum = 0;

        cin >> numdate;

        for(int j=0;j<numdate;j++){
            cin >> data;
            sum += data;
        }
        cout << sum << '\n';
    }
    return 0;
}
