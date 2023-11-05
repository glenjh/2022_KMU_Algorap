#include <iostream>
using namespace std;


int main(){
    int testcase;
    cin >> testcase;
    for(int i=0 ; i<testcase ; i++){
        char board[9][9];
        for(int a =0 ; a<9 ; a++){
            for(int b=0 ; b<9 ; b++){
                board[a][b] = '+';
            }
        }
        board[4][4] = 'O';
        board[5][5] = 'O';
        board[4][5] = 'X';
        board[5][4] = 'X';

        int how_many;
        int black_x , black_y , white_x, white_y;
        cin >> how_many;

        for(int j=0 ; j<how_many/2 ; j++){
            cin >> black_x >> black_y;
            cin >> white_x >> white_y;
            board[black_x][black_y] = 'X';
            for(int k=black_y+1 ; k<=9 ; k++){// 오른쪽 
               if(board[black_x][k] == '+'){
                   break;
               }
               if(board[black_x][k] == 'X'){
                   for(int l=black_y ; l < k ;l++){
                       board[black_x][l] = 'X';
                   }
                   break;
               }
           }
           for(int k=black_y-1 ; k > 0 ; k--){ //왼쪽
                if(board[black_x][k] == '+'){
                    break;
                }
                if(board[black_x][k] == 'X'){
                    for(int l = black_y ; l>k ; l--){
                        board[black_x][l] = 'X';
                    }
                    break;
                }
           } 
           for(int k=black_x+1 ; k<=9 ; k++){ // 아래
               if(board[k][black_y] == '+'){
                   break;
               }
               if(board[k][black_y] == 'X'){
                   for(int l=black_x ; l<k ; l++){
                       board[l][black_y] = 'X';
                   }
                   break;
               }
           }
            for(int k = black_x-1 ; k >0 ; k--){ //위쪽 
                if(board[k][black_y] == '+'){
                    break;
                }
                if(board[k][black_y] == 'X'){
                    for(int l=black_x ; l > k ; l--){
                        board[l][black_y] = 'X';
                    }
                    break;
                }
            }
            for(int k=black_x-1, k_2 = black_y+1 ; (k>0 && k_2<=9) ; k--, k_2++){ // 오른위 대각
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'X'){
                    for(int l = black_x, l_2 = black_y ; l >k && l_2<k_2 ; l--, l_2++){
                        board[l][l_2] = 'X';
                    }
                    break;
                }
            }

            for(int k=black_x-1, k_2 = black_y-1 ; k>0 && k_2 >0 ; k--,k_2--){ // 왼쪽위 대각 
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'X'){
                    for(int l = black_x, l_2 = black_y ; l>k && l_2 >k_2 ; l--,l_2--){
                        board[l][l_2] = 'X';
                    }
                    break;
                }
            }

            for(int k= black_x+1, k_2 = black_y+1 ; k<=9 && k_2 <=9 ; k++, k_2++){ //오른아래 대각
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'X'){
                    for(int l = black_x, l_2 = black_y ; l < k && l_2 <k_2 ; l++, l_2++){
                        board[l][l_2] = 'X';
                    }
                    break;
                }
            }

            for(int k= black_x+1, k_2 = black_y-1 ; k<=9 && k_2>0 ; k++, k_2--){ //왼아래 대각
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'X'){
                    for(int l=black_x, l_2 = black_y ; l<k && l_2 >k_2 ; l++, l_2--){
                        board[l][l_2] = 'X';
                    }
                    break;
                }
            }


            board[white_x][white_y] = 'O';
            for(int k=white_y+1 ; k<=9 ; k++){// 오른쪽 
               if(board[white_x][k] == '+'){
                   break;
               }
               if(board[white_x][k] == 'O'){
                   for(int l=white_y ; l < k ;l++){
                       board[white_x][l] = 'O';
                   }
                   break;
               }
           }
           for(int k=white_y-1 ; k > 0 ; k--){ //왼쪽
                if(board[white_x][k] == '+'){
                    break;
                }
                if(board[white_x][k] == 'O'){
                    for(int l = white_y ; l>k ; l--){
                        board[white_x][l] = 'O';
                    }
                    break;
                }
           } 
           for(int k=white_x+1 ; k<=9 ; k++){ // 아래
               if(board[k][white_y] == '+'){
                   break;
               }
               if(board[k][white_y] == 'O'){
                   for(int l=white_x ; l<k ; l++){
                       board[l][white_y] = 'O';
                   }
                   break;
               }
           }
            for(int k = white_x-1 ; k >0 ; k--){ //위쪽 
                if(board[k][white_y] == '+'){
                    break;
                }
                if(board[k][white_y] == 'O'){
                    for(int l=white_x ; l > k ; l--){
                        board[l][white_y] = 'O';
                    }
                    break;
                }
            }
            for(int k=white_x-1, k_2 = white_y+1 ; (k>0 && k_2<=9) ; k--, k_2++){ // 오른위 대각
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'O'){
                    for(int l = white_x, l_2 = white_y ; l >k && l_2<k_2 ; l--, l_2++){
                        board[l][l_2] = 'O';
                    }
                    break;
                }
            }

            for(int k=white_x-1, k_2 = white_y-1 ; k>0 && k_2 >0 ; k--,k_2--){ // 왼쪽위 대각 
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'O'){
                    for(int l = white_x, l_2 = white_y ; l>k && l_2 >k_2 ; l--,l_2--){
                        board[l][l_2] = 'O';
                    }
                    break;
                }
            }

            for(int k= white_x+1, k_2 = white_y+1 ; k<=9 && k_2 <=9 ; k++, k_2++){ //오른아래 대각
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'O'){
                    for(int l = white_x, l_2 = white_y ; l < k && l_2 <k_2 ; l++, l_2++){
                        board[l][l_2] = 'O';
                    }
                    break;
                }
            }

            for(int k= white_x+1, k_2 = white_y-1 ; k<=9 && k_2>0 ; k++, k_2--){ //왼아래 대각
                if(board[k][k_2] == '+'){
                    break;
                }
                if(board[k][k_2] == 'O'){
                    for(int l=white_x, l_2 = white_y ; l<k && l_2 >k_2 ; l++, l_2--){
                        board[l][l_2] = 'O';
                    }
                    break;
                }
            }
            
        }
        int black_num = 0 , white_num = 0;
        for(int j=1 ; j<9 ; j++){
            for(int k=1 ; k<9 ;k++){
                if(board[j][k] == 'X'){ black_num++; }
                else if(board[j][k] == 'O'){ white_num++; }
            }
        }
        cout << black_num << " " << white_num << endl;
        for(int j=1 ; j<9 ; j++){
            for(int k=1 ; k<9 ;k++){
                cout << board[j][k];
            }
            cout << endl;
        }
    }
    return 0;
}
