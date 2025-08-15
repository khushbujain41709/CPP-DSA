// Even binary number has 0 at end
// Odd binary number has 1 at end
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string dec_to_bin(int& decimal){
    string result = "";
    while(decimal > 0){
        if(decimal % 2 == 0){
            result += "0";
        }
        else{
            result += "1";
        }
        decimal = decimal/2;
    }
    reverse(result.rbegin() , result.rend());
    return result;
}
int main(){
    int num = 31;
    cout<<dec_to_bin(num);
    return 0;
}