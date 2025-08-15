/*
Input
91730629
Output
123032
Answer
91230320
Checker Log
wrong answer expected '91230320', found '123032'
*/
// Take string as an input instead of an integer.
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i = 0; i<s.size(); i++){
        if(i == 0 && s[i] == '9'){
            cout<<9;
            continue;
        }
        else if((s[i] - '0') >= 5){
            int inverted = 9 - (s[i] - '0');
            s[i] = inverted + '0';
        }
        cout<<s[i] - '0';
    }
    // int x;
    // cin>>x;
    // if(x == 9){
    //     cout<<9<<endl;  // ans should be a positive number
    // }
    // else{
    //     int t = 0;
    //     int rev = 0;
    //     while(x > 0){
    //         int digit = x % 10;
    //         if(digit >= 5){
    //             digit = 9 - digit;
    //         }
    //         else{
    //             digit = digit;
    //         }
    //         t = t * 10 + digit;
    //         x = x/10;
    //     }
    //     while(t > 0){
    //         rev *= 10;
    //         int digit = t % 10;
    //         rev += digit;
    //         t = t/10;
    //     }
    //     cout<<rev<<endl;
    // }
    return 0;
}