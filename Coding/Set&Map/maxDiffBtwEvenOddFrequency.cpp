// Leetcode 3442
#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
int maxDifference(string s) {
    unordered_map<char, int> mp;
    unordered_map<int, char> mp2;
    for(int i = 0; i<s.size(); i++){
        mp[s[i]]++;
    }
    for(auto x : mp){
        mp2[x.second] = x.first;
    }
    int odd = INT_MIN;
    int even = INT_MAX;
    for(auto x : mp2){
        if(x.first % 2 != 0){
            odd = max(odd, x.first);
        }
        else{
            even = min(even , x.first);
        }
    }
    return odd - even;
}
int main(){
    
    return 0;
}