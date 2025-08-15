#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// n*m*k is the number of multiplication of matrix n*m and m*k matrices
// f(arr, i, j) = min( f(arr, i, k) + f(arr, j, k) + arr[i]*arr[j]*arr[k] )and k = [i+1 , j -1] where f(arr, i , j) is the minimum cost to multiply all matrices in the range (i,j)
vector<vector<int>> dp;
int f(int i, int j , vector<int>& arr){
    if(i == j || i+1 == j) return 0; // as singleton matrix [40] takes 0 multplication and matrix [4,2] also takes 0 multiplication
    int ans = INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    for(int k = i+1; k < j; k++){
        ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    dp.resize(n, vector<int> (n, -1));
    return f(0, n-1, arr);
}

// Bottom Up - Skip it - Hard to Understand
vector<vector<int>> dp;
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    dp.resize(n, vector<int> (n, 0));
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 < n; i++){ 
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1]*arr[j]*arr[k]);
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    return 0;
}