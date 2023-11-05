#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string sub_big_num(string a, string b){
    string retrun_string = "";
    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());
    int len_a = a.length();
    int len_b = b.length();

    int carry = 0;

    for(int i=0 ; i < len_b ; i++){
        int sub = (a[i] - '0') - (b[i] - '0') - carry;  
        if(sub < 0 ){
            carry = 1;
            sub += 10;
        }
        else carry = 0;
        retrun_string += to_string(sub);
    }

    for(int i=len_b ; i< len_a ; i++){
        int sub = (a[i] - '0') - carry;
        if(sub < 0){
            sub += 10;
            carry = 1;
        }else carry = 0;
        retrun_string += to_string(sub);
    }
    reverse(retrun_string.begin() , retrun_string.end());
    return retrun_string;
}


int main(){
    int testcase;
    cin >> testcase;
    for(int i=0; i < testcase ; i++){
        string input , head , tail;
        vector<string> v;
        cin >> input;
        if(input.length() == 1){
            cout << 0 << endl;
            continue;
        }
        head = input.substr(0,input.length()-1);
        tail = input[input.length()-1];
        v.push_back(tail);
        string rel = sub_big_num(head , tail);
        while(rel.length() > 1){
            string rel_head, rel_tail;
            rel_head = rel.substr(0 ,rel.length() - 1);
            rel_tail = rel[rel.length() - 1];
            // cout << "rel" << rel <<endl;
            // cout << "tail" << rel_tail << endl;
            // cout << "head" <<rel_head <<endl;
            v.push_back(rel_tail);
            rel = sub_big_num(rel_head, rel_tail);
        }
        int key;
        vector<string> n_v;
        reverse(v.begin() , v.end());
        for(int i=0;i<v.size() ;i++){
            if(v[i] != "0"){
                key = i;
                break;
            }
        }
        for(int i= key;i<v.size();i++){
            n_v.push_back(v[i]);
        }
        if(rel == "0"){
            //cout << 1 <<endl;
            for(int i=0;i<n_v.size() ;i++){
                cout << stoi(n_v[i]);
            }
            cout << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
