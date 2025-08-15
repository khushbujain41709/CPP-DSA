// CSES Problem
// f(n) returns minimum number of steps to reduce n to 0.
// f(n) = 1 + min( f(n-di) ) where di is the set of different digits of n.
// i belongs to 0 to k-1 where k is number of digits.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> getDigits(int n){
    vector<int> digits;
    while(n > 0){
        if(n % 10 != 0){  // push all digits except zero as n- 0 = n, goes to infinite loop.
            digits.push_back(n%10);    
        }
        n /= 10;
    }
    return digits;
}

// Using memoization
int f(int n, vector<int>& dp){
    // base cases
    if(n == 0) return 0;
    if(n <= 9) return 1;
    vector<int> digits = getDigits(n);
    int result = INT_MAX;
    if(dp[n] != -1) return dp[n];
    int sizzi = digits.size();
    for(int i = 0 ; i<sizzi; i++){
        result = min(result, f(n - digits[i], dp));
    }
    return dp[n] = result + 1;
}

// using tabulation
int ft(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    vector<int> dp(n+1);
    // base cases
    dp[0] = 0;
    for(int i = 0; i<= 9;i++){
        dp[i] = 1;
    }
    for(int i = 10; i<= n; i++){
        dp[i] = INT_MAX;
        vector<int> digits = getDigits(i);
        for(int k = 0; k<digits.size(); k++){
            dp[i] = min(dp[i], dp[i - digits[k]]);
        }
        dp[i] = 1 + dp[i];
    }
    return dp[n];
    // Index         : 0 1 2 3 4 5 6 7 8 9 10 11 12
    // Content of dp : 0 1 1 1 1 1 1 1 1 1 2   3  3
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1 , -1);
    cout<<f(n, dp)<<endl;
    cout<<ft(n)<<endl;
    return 0;
}