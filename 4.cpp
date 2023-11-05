#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    vector<int> arr(3);
    for(int i=0;i<t;i++){
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr.begin(), arr.end());
        cout << arr[0] <<' ' << arr[1] << ' ' << arr[2]<<endl;
    }
    return 0;
}