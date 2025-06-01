// Print factorial of first 25 natural numbers and modulo the result by 10^9 + 7
// fact[i]  = i * fact[i-1]
// fact[i] % c = (i % c * fact[i-1] % c) % c
#include<iostream>
#include<vector>
using namespace std;
vector<long long int> factorial(int n){ // n = 25
    int MOD = 1000000000 + 7;
    vector<long long int> fact(n+1 , 1);  // index from 0 to 25
    for(int i = 2; i<= n ; i++){
        fact[i] = ((i % MOD) * (fact[i-1] % MOD)) % MOD;
    }
    return fact;
}
int main(){
    vector<long long int> ans = factorial(25);
    for(int i = 0;i<ans.size();i++){
        cout<<i<< "! = " <<ans[i] <<endl;
    }
    return 0;
}