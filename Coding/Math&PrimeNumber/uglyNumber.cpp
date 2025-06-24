// Leetcode - 263
// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
// Given an integer n, return true if n is an ugly number.
#include<iostream>
using namespace std;
bool isUgly(int n){
    if(n == 0) return false; // see testcase or given positive integer as 0 is not a positive number.
    if(n == 1) return true;
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    return(n == 1);
}
int main(){
    cout<<isUgly(60);
    return 0;
}