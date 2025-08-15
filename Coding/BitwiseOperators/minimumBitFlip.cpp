// Minimum number of bits to convert from one number to another
// count set bits in x^y
#include<iostream>
using namespace std;
int main(){
    int x = 23;
    int y = 31;
    cout<<__builtin_popcount(x^y)<<endl;
    return 0;
}