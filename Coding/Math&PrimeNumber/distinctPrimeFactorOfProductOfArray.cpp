// Leetcode - 2521
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
// gives TLE in case [11,14,12,4,3,17,9,15]
bool isPrimeNumber(int n){
    for(int i = 2;i<=sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;
}
int distinctPrimeFactors(vector<int>& nums) {
    int n = nums.size();
    int product = 1;
    for(int i = 0;i<n;i++){
        product *= nums[i];
    }
    int prime_factors = 0;
    for(int i = 2;i<product;i++){
        if(isPrimeNumber(i) && product % i == 0){
            prime_factors ++;
        }
    }
    return prime_factors;
}
// Method 2 
// Find largest number mx in array and then finds all prime numbers till mx including it.
// Now make a sieve of size (mx+1) and make it's 0 and 1 index as 0 as we will fill the sieve as done in sieve of eratosthenesis.
// While filling we get all primes below number mx. Now we will push all prime number below mx in an array primes and then check nums array if any element in nums array is divisble by all prime numbers or not.
// If divides any prime number then taken array will be marked as 1 instead of zero and count all ones.
void fillSieve(vector<bool>& sieve){  // By reference is imp
    int n = sieve.size()-1;
    for (int i = 2; i<= sqrt(n); ++i){
        if(sieve[i]){ // Only process if i is still marked as prime
            for (int j = i * i; j <= n; j += i) {  
                sieve[j] = 0 ; // Mark multiples of i as non-prime
            }
        }
    }
}
int distinctPrimeFactorsLeet(vector<int>& nums){  // [2,3,10,6]
    int n = nums.size();
    int prime_factors = 0;
    int mx = -1;
    for(int i = 0;i<n;i++){
        mx = max(mx,nums[i]);
    }
    vector<bool> sieve(mx+1, 1); // 1 means prime
    if(mx+1 > 0) sieve[0] = 0;
    if(mx+1 > 1) sieve[1] = 0;
    fillSieve(sieve);  // [0,0,1,1,0,1,0,1,0,0,0]
    vector<int> primes;
    for(int i = 2;i<= mx;i++){
        if(sieve[i] == 1) primes.push_back(i);  // primes = [2,3,5,7]
    }
    vector<bool> taken(primes.size(),0); // [0,0,0,0]
    for(int i = 0;i<n;i++){
        int ele = nums[i];
        for(int j = 0;j<primes.size();j++){
            if(primes[j] > nums[i]) break; // as 4%5 = 4 not 0 so check till the nums[i] value.
            if(nums[i] % primes[j] == 0) taken[j] = 1; // [1,1,1,0]
        }
    }
    for(int i = 0;i<taken.size();i++){
        if(taken[i] == 1) prime_factors++; // 3
    }
    return prime_factors;
}
int main(){
    vector<int> v = {2,4,3,7,10,6};
    cout<<distinctPrimeFactorsLeet(v);
    return 0;
}