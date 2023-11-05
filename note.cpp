#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string sub(string a, string b){
    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());

    string rel = "";
    for(int i=0 ; i<b.length() ; i++){
        int carry = 0;
        int sub = (a[i] - '0') - (b[i] - '0') - carry;
        if(sub < 0 ){
            sub += 10;
            carry = 1;
        }else{
            carry = 0;
        }
        rel += to_string(sub);
    }
    for(int i=b.length() ; i<a.length() ; i++){
        int carry = 0;
        int sub = (a[i] -'0') - carry;
        if(sub < 0){
            sub += 10;
            carry = 1;
        }else{
            carry = 0;
        }
        rel += to_string(sub);
    }
    reverse(rel.begin() , rel.end());
    return rel;
}
int main(){
    int testcase;
    cin >> testcase;
    for(int i=0 ; i<testcase ; i++){
        int n;
        int arr[49][49] = {0,};
        cin >> n;

        int x = 0 , y=n/2, start=1;
        arr[x][y] = start;
        start++;

        while(start <= n*n){
            if((start-1)%n == 0){
                x++;
                y = y;
                arr[x][y] = start;
                start++;
            }else{
                if(x-1 < 0){
                    x = n-1;
                    y++;
                    arr[x][y] = start;
                    start++;
                }else if(y+1 > n-1){
                    x--;
                    y=0;
                    arr[x][y] = start;
                    start++;
                }else{
                    x--;
                    y++;
                    arr[x][y] = start;
                    start++;
                }
            }
        }
    }
    return 0;
}


// for(int j=0 ; j<how_many/2 ; j++){
//             cin >> black_x >> black_y;
//             cin >> white_x >> white_y;
//             board[black_x][black_y] = 'X';
//             for(int k=black_y+1 ; k<=9 ; k++){// 오른쪽 
//                if(board[black_x][k] == '+'){
//                    break;
//                }
//                if(board[black_x][k] == 'X'){
//                    for(int l=black_y ; l < k ;l++){
//                        board[black_x][l] = 'X';
//                    }
//                    break;
//                }
//            }
//            for(int k=black_y-1 ; k > 0 ; k--){ //왼쪽
//                 if(board[black_x][k] == '+'){
//                     break;
//                 }
//                 if(board[black_x][k] == 'X'){
//                     for(int l = black_y ; l>k ; l--){
//                         board[black_x][l] = 'X';
//                     }
//                     break;
//                 }
//            } 
//            for(int k=black_x+1 ; k<=9 ; k++){ // 아래
//                if(board[k][black_y] == '+'){
//                    break;
//                }
//                if(board[k][black_y] == 'X'){
//                    for(int l=black_x ; l<k ; l++){
//                        board[l][black_y] = 'X';
//                    }
//                    break;
//                }
//            }
//             for(int k = black_x-1 ; k >0 ; k--){ //위쪽 
//                 if(board[k][black_y] == '+'){
//                     break;
//                 }
//                 if(board[k][black_y] == 'X'){
//                     for(int l=black_x ; l > k ; l--){
//                         board[l][black_y] = 'X';
//                     }
//                     break;
//                 }
//             }
//             for(int k=black_x-1, k_2 = black_y+1 ; (k>0 && k_2<=9) ; k--, k_2++){ // 오른위 대각
//                 if(board[k][k_2] == '+'){
//                     break;
//                 }
//                 if(board[k][k_2] == 'X'){
//                     for(int l = black_x, l_2 = black_y ; l >k && l_2<k_2 ; l--, l_2++){
//                         board[l][l_2] = 'X';
//                     }
//                     break;
//                 }
//             }

//             for(int k=black_x-1, k_2 = black_y-1 ; k>0 && k_2 >0 ; k--,k_2--){ // 왼쪽위 대각 
//                 if(board[k][k_2] == '+'){
//                     break;
//                 }
//                 if(board[k][k_2] == 'X'){
//                     for(int l = black_x, l_2 = black_y ; l>k && l_2 >k_2 ; l--,l_2--){
//                         board[l][l_2] = 'X';
//                     }
//                     break;
//                 }
//             }

//             for(int k= black_x+1, k_2 = black_y+1 ; k<=9 && k_2 <=9 ; k++, k_2++){ //오른아래 대각
//                 if(board[k][k_2] == '+'){
//                     break;
//                 }
//                 if(board[k][k_2] == 'X'){
//                     for(int l = black_x, l_2 = black_y ; l < k && l_2 <k_2 ; l++, l_2++){
//                         board[l][l_2] = 'X';
//                     }
//                     break;
//                 }
//             }

//             for(int k= black_x+1, k_2 = black_y-1 ; k<=9 && k_2>0 ; k++, k_2--){ //왼아래 대각
//                 if(board[k][k_2] == '+'){
//                     break;
//                 }
//                 if(board[k][k_2] == 'X'){
//                     for(int l=black_x, l_2 = black_y ; l<k && l_2 >k_2 ; l++, l_2--){
//                         board[l][l_2] = 'X';
//                     }
//                     break;
//                 }
//             }





