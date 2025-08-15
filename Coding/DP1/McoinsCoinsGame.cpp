// Sphere Online Jugde - M Coins - Coins Game
// f(n , K , L) - determines whether n is a loosing state or winning state
// winning state - 1 , loosing state - 0
// f(n , K , L) = ! (f(n-1 , K , L) && f(n-K , K , L) && f(n-L , K , L))
// agar f(n-1 , K , L), f(n-K , K , L), f(n-L , K , L) ye sab winning state hai toh f(n , K , L) ye state loosing state hogi.
// agar f(n-1 , K , L), f(n-K , K , L), f(n-L , K , L) inme se koi bhi ek loosing state hai toh f(n , K , L) winning state hogi.
// Let K = 2 and L = 3
// Value of n : 1 2 3 4 5 6 7 8 9 10
// Win/ Loose : 1 1 1 0 1 1 1 0 1 1
// These values depends on values of K and L.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int K, L, m;
    cin>>K>>L>>m;
    vector<bool> dp(1000005, 0);  // bcoz 1000000 is given in question
    dp[1] = 1;
    dp[K] = 1;
    dp[L] = 1;
    // computing all 1000000 values in dp vector and storing it
    for(int i = 2 ; i<= 1000000; i++){
        if(i == K || i == L ) continue;
        dp[i] = ! (dp[i-1] && (( i - K >= 1) ? dp[i - K] : 1) && (( i - L >= 1) ? dp[i - L] : 1)); // as x && 1 = x
    }
    // as given in question... testing for m values
    for(int i = 0;i<m;i++){
        int n;
        cin>>n;
        if(dp[n] == 1){
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
    return 0;
}