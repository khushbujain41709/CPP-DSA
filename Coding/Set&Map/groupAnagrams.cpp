// Leetcode 49
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// strs = ["eat","tea","tan","ate","nat","bat"]
// make contents of the map like this :
/**
 *    | abt, {bat}         | 
 *    | ant, {tan,nat}     |
 *    | aet, {eat,tea,ate} |            
 *    |____________________|
 */
// Everytime, We are sorting each elements so for total k size elements, TC = O(klogk). Therefore, total TC = O(n*klogk)
// SC = O(n*k) where k is size of the string.
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string , vector<string> > m;
    int n = strs.size();
    for(int i = 0;i < n;i++){
        string lexo = strs[i];
        sort(lexo.begin(), lexo.end());
        if(m.find(lexo) == m.end()){
            vector<string> v;
            v.push_back(strs[i]);
            m[lexo] = v;
        }
        else{
            m[lexo].push_back(strs[i]);
        }
    }
    for(auto x : m){
        ans.push_back(x.second);
    }
    return ans;
}
int main(){
    
    return 0;
}