// Leetcode 5
// If we pass string and  it's reverse in the longest common substring question, then answer will be wrong.
// If we use brute force solution,then TC = O(n^3) as we use two pointers i and j and check for each substring that is it a palindrome or not.
// Hint : i to j is palindrome if i+1 to j-1 is palindrome and a[i] == a[j]
// dp[i][j] represents whether from i to j s[i] to s[j] contains a palindromic substring or not.
// Since we only see i<j to avoid repition, we fill lower triangular matrix with zero.
// diagonal is always 1 as a to a is always a palindrome.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    int count = n; // see example 1
    vector<vector<int>> dp(n , vector<int> (n, 1)); // since we are traversing only upper triangle and for default main diagonal filling.
    int maxLen = INT_MIN;
    int start = 0;
    int end = 0;
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
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        start = i;
                        end = j;
                    }
                }
                else{
                    if(dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        count++;
                        if(j - i + 1 > maxLen){
                            maxLen = j - i + 1;
                            start = i;
                            end = j;
                        }
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
    }
    // substr(pos, len)
    return s.substr(start , end - start + 1);
}
int main(){
    return 0;
}