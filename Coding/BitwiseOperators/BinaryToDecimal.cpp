// y << x means in y binary form x zeroes are added in right side.
// 1 << x reperesents all 2^x form numbers.
#include<iostream>
using namespace std;
int binary_To_decimal(string& binary){
    int n = binary.size();
    int result = 0;
    for(int i = n-1;i>=0;i--){
        char ch = binary[i]; // last character
        int num = ch - '0'; // string to number conversion, substracting scii of 0 with ascii of 0 and ascii of 1 with ascii of 1.
        result += num*(1<<(n-i-1)); // first index like 1<<0 is 1 ans 1<<1 is 10 that is 2 so on.
    }
    return result;
}
int main(){
    string binary = "0111";
    cout<<binary_To_decimal(binary);
    return 0;
}