// Factors always exist in pairs.
// If i is the factor of n then n/i will also be factor of n.
// Prime number has 2 factors.
// Composite number has even number of factors except perfect squares.
// If any number has factors except 1 and n then for sure half of the factors will lie before <= sqrt(n)
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n == 1){
        return false;
    }
    for(int i = 2;i<=sqrt(n);i++){  // or use for(int i = 2;i<= n-1;i++) in loop but using sqrt we optimize the loop.
        if(n%i == 0) return false;
    }
    return true;
}
int main(){
    cout<<isPrime(9);
    return 0;
}