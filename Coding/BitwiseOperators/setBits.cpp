// set bits of a number are bits having value 1 in number's binary form.
// Ex - 11 that is 00001011 have 3 set bits.
// For this we use, built-in function, __builtin_popcount(integer)
// Without builtin function -
// If x anf x -1 number, there are two regions, one is same part and another is flipped part.
// The flipped region starts in x-1 at the last set bit of x.
// Use bitwise and (&) as 0 & 0 = 0 and 1 & 1 = 1 that is when input are same , output is same. But when input is flipped, output is zero.
// Use bitwise and between x and x-1 and store it in x. This will elimate one set bit. Repeat this till we get x = 0 and . Number of steps = Number of set bits.
// x = 22 and x-1 = 21 now x & x-1 = 20. Step - 1
// x = 20 and x-1 = 19 now x & x-1 = 16. Step - 2
// x = 16 and x-1 = 15 now x & x-1 = 0. Step - 3
// count = 3

// This algorithm is known as Brian Kernigler's Algorithm.
#include<iostream>
using namespace std;
int count_set_bits(int num){
    return __builtin_popcount(num);
}
int count_set_bits_2(int n){
    int count = 0;
    while(n > 0){
        count ++;
        n = (n & (n-1));
    }
    return count;
}
int main(){
    int num = 11;
    cout<<count_set_bits_2(num);
    return 0;
}