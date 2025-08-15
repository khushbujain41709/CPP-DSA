<<<<<<< HEAD
// GFG
=======
>>>>>>> 81ea8a2b56bab97a32db007e74cbd96d50711cf7
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// make m+1 row and n+1 column 2D vector
// dp[i][j] represents continuous same characters from backwards of string
// row 0 and column 0 is for storing bases cases and lcs of "" and s[0 - (m-1)] is 0. Similarly lcs of "" and t[0 - (n-1)] is 0.
// for filling dp[i][j] if s[i] != t[i], fill 0
// for filling dp[i][j] if s[i] == t[i], fill 1 + diagonal element
// for filling dp[i][j] check s[i-1] and t[j-1]
// answer will be the maximum element in whole 2D vector.
vector<vector<int>> dp;
int longestCommonSubstr(string& s1, string& s2) {
    // your code here
    int m = s1.size();
    int n = s2.size();
    int maxx = INT_MIN;
    dp.resize(m+1, vector<int>(n+1 , 0));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            if(dp[i][j] > maxx) maxx = dp[i][j];
        }
    }
    return maxx;
}
int main(){
    
    return 0;
}