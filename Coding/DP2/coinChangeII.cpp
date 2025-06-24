// Leetcode 518
#include<iostream>
#include<vector>
using namespace std;
/* let amount be 6 and coins be {1, 2, 5}
                                     6
                           __________|__________
                         1/         2|         5\
                        5             4          1
                      __|__         __|__       ___|__
                    1/  |2 \5     1/ 2|  \5   1/  2|  \5
                    4  3   0      3   2   ~   0    ~   ~
              __/___            __|___  
            1/  2|  \5        1/  2|   \5
            3   2    ~        2    1    ~
            This is not complete recursion tree but see repeating pattern 
            2 1 1 2 and 1 1 2 2 , similarly 2 1 1 1 1 and 1 1 1 1 2   

So, correct tree is,
                                     6
                           __________|__________
                         1/          2|         5\
                        5              4          1
                      __|__          __|__        |
                    1/  |2 \5      2|     |5      5 
                    4   3    0      2      ~      ~
                   /|\  /\   |      /\


*/
vector<vector<int>> dp;
int helper(int idx, int amount, vector<int>& coins){
    int n = coins.size();
    if(amount == 0) return 1;
    if(amount < 0) return 1;
    int res = 0;
    if(dp[idx][amount] != -1) return dp[idx][amount];
    for(int i = idx; i<n; i++){  
        // i = idx as counting starts repeating, we will get 2 1 1 2 and 1 1 2 2 from different calls.
        if(amount - coins[i] < 0) continue;
        res += helper(i, amount - coins[i] , coins);
    }
    return dp[idx][amount] = res;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    dp.resize(n, vector<int>(amount + 1, -1));
    return helper(0, amount, coins);
}
int main(){
    
    return 0;
}