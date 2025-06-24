#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// To print LCS, it is necessary to use bottom up approach of finding LCS.
// After tabulation of length of LCS, just trace path backward.
// Reverse the final answer.
vector<vector<int>> dp;
string longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    dp.resize(m+1, vector<int>(n+1 , 0));
    // fill dp vector
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
    // trace back
    string ans = "";
    int i = m;
    int j = n;
    while(i > 0 && j > 0){  // imp line
        if(text1[i-1] == text2[j-1]){
            ans += text1[i-1];
            i = i-1;
            j = j-1;
        }
        else{
            if(dp[i-1][j] == dp[i][j]){
                i = i-1;
            }
            else if(dp[i][j-1] == dp[i][j]){
                j = j-1;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    cout<<longestCommonSubsequence("adbecfh", "apbcqef")<<endl;
    return 0;
}