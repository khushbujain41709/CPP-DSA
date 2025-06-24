// Leetcode 1207
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
bool uniqueOccurrences(vector<int>& arr){  // arr = [1,2,2,1,1,3]
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i = 0;i < n;i++){
        mp[arr[i]]++;  // number, frequency pairs // O(n)
    }
    // now mp contains : [1,3] , [2,2] , [3,1]
    unordered_set<int> s;
    for(auto x : mp){
        int freq = x.second;
        if(s.find(freq) == s.end()){
            s.insert(freq);
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    
    return 0;
}