#include <iostream>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    
    for(int i=0 ; i<testcase ; i++){
        int n;
        cin >> n;
        int arr[50][50] = {0,};
        int start = 1;
        int one = 1;
        int two = n/2 + 1;
        arr[one][two] = start;
        start++;
        
        while(start <= n*n){
            if((start - 1)%n == 0){
                one++;
                arr[one][two] = start;
                start++;
            }else{
                if(one - 1 < 1){
                    one = n;
                    two++;
                    arr[one][two] = start;
                    start++;
                }
                else if(two+1 > n){
                    one--;
                    two = 1;
                    arr[one][two] = start;
                    start++;
                }else{
                    one--;
                    two++;
                    arr[one][two] = start;
                    start++;
                }
            }
        }
        for(int j=1 ; j<=n ; j++){
            for(int k=1 ; k<=n ; k++){
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
