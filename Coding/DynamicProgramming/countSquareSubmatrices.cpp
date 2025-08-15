// Leetcode 1277
#include<iostream>
#include<vector>
using namespace std;
// dp[i][j] means the size of biggest square with A[i][j] as bottom-right corner.
// dp[i][j] also means the number of squares with A[i][j] as bottom-right corner.
int countSquares(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int> (n, 0));
    int ans = 0;
    // Initialize first column of DP table
    // Each cell in first column can only form a 1x1 square if matrix[i][0] = 1
    for(int i = 0; i< m; i++){
        dp[i][0] = matrix[i][0];
        ans += dp[i][0];  // add all as 1+0+0 = 1 indicates only 1 square
    }
    // Initialize first row of DP table
    // Each cell in first row can only form a 1x1 square if matrix[0][j] = 1
    for(int i = 1; i< n; i++){  // i = 1 to avoid doubel counting dp[0][0]
        dp[0][i] = matrix[0][i]; 
        ans += dp[0][i]; // add all as 1+0+0 = 1 indicates only 1 square
    }
    for(int i = 1 ; i<m; i++){
        for(int j = 1; j<n; j++){
            if(matrix[i][j] == 1){
                // adding add as if current cell is 1 then it will add to total squares 
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1] , dp[i-1][j]));
            }
            ans += dp[i][j];
        }
    }
    return ans;
}
int main(){
    
    return 0;
}