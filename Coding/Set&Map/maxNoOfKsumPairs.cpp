// Leetcode 1679
// Just do a dry run on the test cases.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxOperations(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mp;
    int count = 0;
    for(int i = 0; i<n;i++){
        if(mp[k - arr[i]] > 0){
            count ++;
            mp[k- arr[i]]--;
        }
        else{
            mp[arr[i]]++;
        }
    }
    return count;
}
int main(){
    
    return 0;
}