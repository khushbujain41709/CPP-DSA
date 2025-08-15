// Leetcode 583
#include<iostream>
#include<vector>
using namespace std;
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
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    int len = longestCommonSubsequence(word1, word2);
    return (m - len) + (n - len);
}
int main(){
    
    return 0;
}