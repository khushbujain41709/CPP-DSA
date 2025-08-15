// Leetcode 63
#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[m][n];

    // Starting point
    if(obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;

    // First column - agar 1st column mei obstacle aaya toh obstacle k aage k boxes 0 honge
    for(int i = 1; i < m; ++i) {
        if(obstacleGrid[i][0] == 1)
            dp[i][0] = 0;
        else { // if previous box has zero then it current box is also zero
            dp[i][0] = dp[i-1][0];
        }    
    } 

    // First row - agar 1st row mei obstacle aaya toh obstacle k aage k boxes 0 honge
    for(int j = 1; j < n; ++j) {
        if(obstacleGrid[0][j] == 1)
            dp[0][j] = 0;
        else{  // if previous box has zero then it current box is also zero
            dp[0][j] = dp[0][j-1];
        }    
    }

    for(int i = 1 ; i < m; i++){
        for(int j = 1 ; j < n; j++){
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0; 
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
int main(){
    
    return 0;
}