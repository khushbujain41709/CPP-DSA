// Leetcode 647
#include<iostream>
#include<vector>
using namespace std;
int countSubstrings(string s) {
    int n = s.size();
    int count = n; // see example 1
    vector<vector<int>> dp(n , vector<int> (n, 1)); // since we are traversing only upper triangle and for default main diagonal filling.
    int maxLen = 0;
    // fill other diagonals
    for(int k = 1; k < n; k++){
        for(int i = 0 , j = k ; i <= n-1-k, j<n; j++, i++){
            if(s[i] != s[j]){
                dp[i][j] = 0;
            }
            else{
                // if (i to j) substring id of length 2
                if(j == i+1){
                    dp[i][j] = 1;
                    count++;
                    maxLen = max(j - i + 1, maxLen);
                }
                else{
                    if(dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        count++;
                        maxLen = max(j - i + 1, maxLen);
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
    }
    return count;
}
int main(){
    return 0;
}