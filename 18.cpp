#include <iostream>
using namespace std;


int main(void){
    int testcase;
    cin >> testcase;
    for(int i= 0 ; i<testcase ; i++){
        int r, s, t;
        cin >> r >> s >> t;

        int **first = new int*[r]; //첫번째 배열
        for(int j=0 ; j<r ; j++){
            first[j] = new int[s];
        }

        for(int j=0 ; j<r ; j++){
            for(int k=0 ; k<s ;k++){
                cin >> first[j][k];
            }
        }

        int **second = new int*[s]; //두번째 배열
        for(int j=0 ; j<s ; j++){
            second[j] = new int[t];
        }

        for(int j=0 ; j<s ; j++){
            for(int k=0 ; k<t ;k++){
                cin >> second[j][k];
            }
        }

        int **answer = new int*[r]; //정답을 담을 배열
        for(int j=0 ; j<r ; j++){
            answer[j] = new int[t];
        }

        for(int j=0 ; j<r ;j++){
            for(int k=0 ; k<t ;k++){
                answer[j][k] = 0;
            }
        }

        for(int j=0 ; j<r ; j++){ //3
            for(int k=0 ; k<t ;k++){ //2
                for(int l=0 ; l<s ; l++){ //5
                    answer[j][k] += first[j][l] * second[l][k];
                }
            }
        }

        for(int j=0 ; j<r ; j++){
            for(int k=0 ; k<t ;k++){
                cout << answer[j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
