#include<iostream>
#include<climits>
using namespace std;
int main(){
    int x = INT_MAX;
    cout<<x<<endl;
    cout<<(x*2)<<endl; // -2

    // method 1
    long long int y = INT_MAX;
    cout<<y<<endl;
    cout<<(y*2)<<endl; 

    // method 2
    //  (a + b) % c = ((a % c) + (b % c)) % c

    //  (a * b) % c = ((a % c) * (b % c)) % c

    //  (a - b) % c = ((a % c) - (b % c) + c) % c as c % c = 0
    //  Example : (22 - 14) % 5 = 3 as (22 % 5 - 14 % 5 + 5 ) % 5 = 3

    //  (a / b) % c can be calculated using inverse modulo arithmetic which can be calculated using Fermat's Theorem and Extended Euclid's Algorithm.

    // Modulo with 10^9 + 7 is used to avoid integer value overflow that is when we need answer in integer range.
    /// 10^9 + 7 is a prime number in integer range.
    int z = INT_MAX;
    cout<< z % 5 <<endl; // since z % 5 = 2 so z + 2 % 5 must be 4
    cout<<( x % 5 + 2 % 5 ) % 5 <<endl;


    return 0;
}