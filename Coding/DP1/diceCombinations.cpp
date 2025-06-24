// CSES Problem
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

// Using Memoization
long long dice(int n, vector<long long>& dp){
    if(n == 0) return 1;  // when we get n == 0, we get one way to throw
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    long long res = 0;
    for(int i = 1 ; i<= 6;i++){
        if(n - i < 0 ) break;  
        // as if n = 3 at i = 4 we get -1 then at i = 5,6 we will negative values.
        res = (res % MOD + dice(n-i,dp) % MOD) % MOD;
    }
    return dp[n] = res % MOD;
}
long long diceT(int n){
    if(n == 0) return 1;  // when we get n == 0, we get one way to throw
    if(n == 1) return 1;
    vector<long long> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int k = 2 ; k <= n; k++){
        long long res = 0;
        for(int i = 1 ; i<= 6;i++){
            if(k - i < 0 ) break;  
            // as if n = 3 at i = 4 we get -1 then at i = 5,6 we will negative values.
            res = (res % MOD + dp[k-i] % MOD) % MOD;
        }
        dp[k] = res % MOD;
    }
    return dp[n] % MOD;
}
// Using Tabulation
int main(){
    int n;
    cin>>n;
    vector<long long> dp(n+1, -1);
    cout<<dice(n,dp)<<endl;
    cout<<diceT(n);
    return 0;
}