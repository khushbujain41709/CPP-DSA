// Leetcode 1143
// Longest Common Subsequence 
/*
                          let s = adbec and t = apbcq
                                    c != q 
                             /                       \       
                  s = adbec and t = apbc        s = adbe and t = apbcq
                         c == c                       e != q
                            |                  /                     \
                  1 + s = adbe and t = apb    s = adbe and t = apbc   s = adb and t = apbcq
                        1 length for c
*/

#include<iostream>
#include<vector>
using namespace std;

// Memoization
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
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    dp.resize(m, vector<int>(n , -1));
    return helper(text1, text2, m-1, n-1);
}

// Tabulation
// make m+1 and n+1 matrix  where int m = text1.size() and int n = text2.size();
int main(){
    
    return 0;
}
