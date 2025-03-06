// Leetcode - 204 - Count Primes 
// Given a number n, print all primes smaller than n.
// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so.
// Steps - 
// 1) We create a list of all numbers from 2 to n.
// 2) According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than or equal to the square of it. 
// 3) Repeat with all numbers till sqrt(n)
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int countPrimes(int n) { // O(n) almost that is O(n*log(logn)) 
// as number of operations =  n[1/2 + 1/3 + 1/5 + 1/7 +...+ 1/sqrt(n)]
// [1/2 + 1/3 + 1/5 + 1/7 +...+ 1/n] = log(log(n))
// [1/2 + 1/3 + 1/5 + 1/7 +...+ 1/sqrt(n)] = log(log(sqrt(n)))
// Now, let n = 2^32 max value of integer. So, root n = 2^16
// Now, log(root n) base 2 = 16 which gets even more smaller when base increases.
// Again, log(log(root n)) base 2 = 4. Therefore O(n*log(logn)) is equal to O(n).
    if (n <= 2) return 0;  // No primes less than 2
    vector<bool> isPrime(n+1, true);  // Create a boolean array to track prime status
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime numbers
    // Mark non-primes
    for (int i = 2; i<= sqrt(n); ++i) {  // We only need to check up to sqrt(n), TC = O(n)
        if (isPrime[i]){
            for (int j = i * i; j <= n; j += i) {  // Mark multiples of i as non-prime
                isPrime[j] = false;
            }
        }
    }
    // Count the primes
    int count = 0;
    for (int i = 2; i < n; ++i){  // i<n as prime till n that is strictly smaller than n.
        if (isPrime[i]) count++;
    }
    return count;
}
int main(){
    cout<<countPrimes(100);
    return 0;
}