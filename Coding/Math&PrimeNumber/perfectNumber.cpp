// Leetcode - 507
// A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
// Given an integer n, return true if n is a perfect number, otherwise return false.
// Ex - Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.
#include<iostream>
#include<cmath>
using namespace std;
bool checkPerfectNumber(int num) {
    int sum = 0;
    for(int i = 1;i<sqrt(num);i++){
        if(num % i == 0){
            cout<<i<<" ";
            sum += i;
        }
    }
    for(int i = sqrt(num) ;i>=1;i--){
        if(num % i == 0 && (num/i) != num){
            cout<<num/i<<" ";
            sum += num/i;
        }
    }
    return (sum == num);
}
int main(){
    
    return 0;
}