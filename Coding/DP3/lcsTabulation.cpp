#include<iostream>
#include<vector>
using namespace std;
// make m+1 row and n+1 column 2D vector
// dp[i][j] represents lcs of s[0 - i] and t[0 - j]
// row 0 and column 0 is for storing bases cases and lcs of "" and s[0 - (m-1)] is 0. Similarly lcs of "" and t[0 - (n-1)] is 0.
// for filling dp[i][j] if s[i] != t[i], fill max(dp[i-1][j], dp[i][j-1])
// for filling dp[i][j] if s[i] == t[i], fill 1 + diagonal element
// for filling dp[i][j] check s[i-1] and t[j-1]
vector<vector<int>> dp;
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    dp.resize(m+1, vector<int>(n+1 , 0));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    
    return 0;
}