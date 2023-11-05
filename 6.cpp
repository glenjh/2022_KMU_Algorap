#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    int input;
    for(int i=0;i<testcase;i++){
        int rel = 0;
        int sum = 0;
        cin >> input;
        int input_2 = input;
        string s = to_string(input);
        int len = s.length();
        while(input_2 != 0){
            rel = input_2 %10;
            input_2 = input_2/10;
            sum += pow(rel,len);
        }
        if(sum == input){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
