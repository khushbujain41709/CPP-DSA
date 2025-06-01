// Leetcode 1052
// Find that window that has most loss of satisfaction. This is not equal to the least satisfaction.
// currLoss = prevLoss + arr[j] if(grumpy[j] == 1) - arr[i-1] if(grumpy[i-1] == 1)
#include<iostream>
#include<vector>
using namespace std;
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int k = minutes;
    int n = customers.size();
    int prevLoss = 0;
    int maxIndex = 0;
    for(int i = 0;i<k;i++){  // calculate  sum of first window
        if(grumpy[i] == 1) prevLoss += customers[i];
    }
    int maxLoss = prevLoss;
    int i = 1;
    int j = k;
    while(j<n){
        int currLoss = prevLoss;
        if(grumpy[j] == 1) currLoss += customers[j];
        if(grumpy[i-1] == 1) currLoss -= customers[i-1];
        if(maxLoss <= currLoss){
            maxLoss = currLoss;
            maxIndex = i;
        }
        prevLoss = currLoss;
        i++;
        j++;
    }
    // filling window with 0 where we get max loss of satisfaction
    for(int i = maxIndex;i<k+maxIndex;i++){
        grumpy[i] = 0;
    }
    int totalCustomers = 0;
    for(int i = 0;i<n;i++){
        if(grumpy[i] == 0){
            totalCustomers += customers[i];
        } 
    }
    return totalCustomers;
}
int main(){
    
    return 0;
}