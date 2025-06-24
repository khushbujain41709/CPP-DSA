// Leetcode 1312
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Minimum Insertion = s.size() - lps(Longest Palindromic Subsequence) = Minimum Deletion
vector<vector<int>> dp;
int helper(string& text1, string& text2, int i , int j){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(text1[i] == text2[j]){
        return dp[i][j] = 1 + helper(text1, text2, i-1 , j-1);
    }
    else{
        return dp[i][j] = max(helper(text1, text2, i-1 , j) , helper(text1, text2, i , j-1));
    }
}
int longestPalindromeSubseq(string s) {
    int m = s.size();
    string t = s;
    reverse(s.begin(), s.end());
    dp.resize(m, vector<int>(m , -1));
    return helper(s, t, m-1, m-1);
}
int minInsertions(string s){
    int n = s.size();
    return n - longestPalindromeSubseq(s);
}
int main(){
    
    return 0;
}