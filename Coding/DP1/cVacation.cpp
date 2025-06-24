// Atcoder - C Vacation
// f(i, a) = a[i] + max( f(i-1, b) , f(i-1,c) )
// f(i, b) = b[i] + max( f(i-1, a) , f(i-1,c) )
// f(i, c) = c[i] + max( f(i-1, a) , f(i-1,b) )
// Final answer is maximum of a, b, c of last day
// We make 2D DP as both day(i) and activity are changing
#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int>& a, vector<int>& b, vector<int>& c, int n){
    int sum = 0;
    if(n == 1) return max(a[0], max(b[0], c[0]));
    vector<vector<int>> dp(n , vector<int> (3,0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for(int i = 1;i<n;i++){
        dp[i][0] = a[i] + max(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0] , dp[i-1][1]);
    }
    return max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2]));
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<helper(a,b,c,n);
    return 0;
}