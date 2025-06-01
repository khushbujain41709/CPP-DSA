// Leetcode 1122
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> ans;
    map<int , int> mp;
    // fill the ordered map with frequencies as values
    for(int i = 0;i<n1;i++){
        mp[arr1[i]]++;
    }
    // for the elements present in arr2
    for(int i = 0;i<n2;i++){
        if(mp.find(arr2[i]) != mp.end()){
            while(mp[arr2[i]] > 0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
    }
    // for the elements which are not in arr2 but in arr1
    for(auto x : mp){
        while(x.second > 0){
            ans.push_back(x.first);
            x.second --;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}