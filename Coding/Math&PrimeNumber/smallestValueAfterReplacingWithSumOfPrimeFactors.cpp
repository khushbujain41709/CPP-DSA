// Leetcode - 2507
/*
n = 60
60 has 2,3,5 as prime factors - sum = 2+2+3+5 = 12
now, 12 has 2,3 as prime factors - sum = 2+3+2 = 7
again, seven has 7 as prime factors - sum = 7.
so ans is 7.

n = 8
8 has prime factor = 2 so sum = 2+2+2 = 6
6 has prime factors = 2 , 3 so sum = 2+3 = 5
5 has 5 as prime factors, hence sum = 5 which is answer.
*/
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){  // O(root(n))
    for(int i = 2;i<=sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;
}
int smallestValue(int n) { // Overall TC = O(nlogn)
    if(isPrime(n)) return n; // base case
    int sum = 0;
    for(int i = 2 ;i<sqrt(n);i++){  // O(root n) so O(n) including prime case, Overall O(n + logn) including while loop = O(n)
        if(n % i == 0  && isPrime(i)){  // O(root n) because of checking prime number.
            int m = n;
            while(m % i == 0){ // O(log n base i) since m = n
                sum += i;
                m /= i;
            }
        }
    }
    for(int i = sqrt(n);i >= 1;i--){
        if(n % i == 0  && isPrime(n/i)){
            int m = n;
            while(m % (n/i) == 0){
                sum += (n/i);
                m /= (n/i);
            }
        }
    }
    if(sum == n) return n; // This is only case when n = 4 as sum = 2+2 = 4 as goes infinite loop.
    return smallestValue(sum); // Recursion here is logarithmic as 15 = 3*5 so sum 3+5. In logarithmic functions, product becomes sum.So, O(logn)
}
int main(){
    cout<<smallestValue(60);
    return 0;
}