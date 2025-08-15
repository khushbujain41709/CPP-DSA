/*
Given a number N. The task is to reduce the given number N to 1 in the minimum number of steps. You
can perform any one of the below operations in each step.
Operation 1: If the number is even then you can divide the number by 2.
Operation 2: You are allowed to perform n = (n-1).
Operation 3: If the number is divisible by 3 then you can divide the number by 3.
You need to print the minimum number of steps required to reduce the number N to 1 by performing the above
operations.
*/
// Greedy solution will give wrong answer.
/*
 see the overlapping subproblems and f(1) = 0, f(2) = 1, f(3) = 1 and ~ is infinity

                                   f(10)
                          /          |         \
                       f(9)           f(5)      ~
                     /  |  \       /      | \
                  f(8)  ~  f(3)   f(4)    ~  ~
                 /  |  \         /  |   \ 
              f(7) f(4) ~      f(3) f(2) ~
            /  |  \
         f(6)  ~  ~
      /   |   \
    f(5) f(3) f(2)

*/
#include<iostream>
#include<vector>
#include<climits>
#define infinity INT_MAX
using namespace std;

// Using Memoization TC = O(n) SC = O(n)
int f(int n, vector<int>& dp){
   if(n == 1) return 0;
   if(n == 2 || n == 3) return 1;
   if(dp[n] != -1) return dp[n];
   return dp[n] = 1 + min(f(n-1,dp), min((n%2 == 0) ? f(n/2,dp) : infinity , (n%3 == 0) ? f(n/3,dp) : infinity));
}

// Using tabulation TC = O(n) SC = O(n)
int ft(int n){
   if(n == 1) return 0;
   if(n == 2 || n == 3) return 1;
   vector<int>dp(n+1 , -1);  // dp[0] mei kuch bharo mat
   dp[1] = 0;
   dp[2] = 1;
   dp[3] = 1;
   for(int i  = 4; i<=n ;i++){
      dp[i] = 1 + min(dp[i-1], min((i%2 == 0) ? dp[i/2] : infinity , (i%3 == 0) ? dp[i/3] : infinity));
   }
   return dp[n]; 
   // index :  0 1 2 3 4 5 6 7 8 9 10  -> dp array od size 11
   //ft(10) : -1 0 1 1 2 3 2 3 3 2 3
}
int main(){
   int n;
   cin>>n;
   vector<int> dp(n+1,-1);   // dp of size n will give wrong answer
   cout<<f(n,dp)<<endl;
   cout<<ft(n)<<endl;
   return 0;
}