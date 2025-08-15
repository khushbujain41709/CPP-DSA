// Leetcode 72
#include<iostream>
#include<vector>
using namespace std;

// If we do add operation, then i will be at same place and j will move and we intentionally add last character of another word.
// MOVI, LOV -> MOVIV, LOV = MOVI, LO

// If we do delete operation, then j will be at same place and i will move, here we simply delete last character.
// MOVI, LOV -> MOV, LO

// If we do replace operation, then i and j will both shift.
// MOVI, LOV -> MOVV, LOV -> MOV, LO

// ans will be 1 + min(add, delete, replace)

// For base case, 
// if(i < 0) then return j+1 as LOVE, MORELOVE -> "", MORE -> j = 3 and j+1 will be minimum operations to be done.
// if(j < 0) then return i+1 as MORELOVE, LOVE -> MORE, "" -> i = 3 and i+1 will be minimum operations to be removed.
vector<vector<int>> dp;
int helper(string& word1, string& word2, int i, int j){
    // base case
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(word1[i] == word2[j]){
        return dp[i][j] = helper(word1, word2, i-1, j-1);
    }
    else{
        int add = helper(word1, word2, i, j-1);
        int del = helper(word1, word2, i-1, j);
        int replace = helper(word1, word2, i-1, j-1);
        return dp[i][j] = 1 + min(add, min(del, replace));
    }
}
int minDistance(string word1, string word2){
    int m = word1.size();
    int n = word2.size();
    dp.resize(m+1, vector<int>(n+1, -1));
    return helper(word1, word2, m-1, n-1);
}
int main(){
    
    return 0;
}