// Leetcode - 650
#include<iostream>
#include<cmath>
using namespace std;
/*
n = 8 then 
copy all = A
paste = A
copy all = AA
paste = AAAA
copy all = AAAA
pate = AAAAAAAA
hence, minimum number of operations = 6
*/
/*
1) if number is prime then number is naswer.
2) if number is exponent of two then answer is 2*power.Ex for 64 = 2^6 answer is 2*6 = 12
*/
/*
Algo to create n = 20
Find the highest factor of current number -
1) 20 has 10 as highest factor so it will be created using 10 so count = 2. You copy 10 A and paste and this makes 20 A 
2) 10 has 5 as highest factors so count count = 2+2 
3) 5 takes 5 opeartions so count = 4+5 = 9 which is answer.
*/
/*
n = 90
90/45 count = 2
45/15 count = 3
15/5  count = 3
5/1   count = 5
Total operations = 13
*/
bool isPrime(int n){
    for(int i = 2;i<=sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;
}
int highest_factor(int n){
    int hf = 0;
    for(int i = 2;i<=sqrt(n);i++){
        if(n % i == 0){
            hf = n/i;
            return hf;
        }
    }
    return 1; // if prime return 1
}
int minSteps(int n) {  // O(sqrt(n)logn)
    if(n == 1) return 0;
    if(isPrime(n)) return n;
    int count = 0;
    while(n > 1){  // max TC = O(log(n))
        if(isPrime(n)){  // TC = O(sqrt(n))
            count += n;
            return count ;
        }
        count += n/highest_factor(n); // TC = O(sqrt(n))
        n = highest_factor(n);
    }
    return count;
}
int main(){
    cout<<minSteps(90);
    return 0;
}