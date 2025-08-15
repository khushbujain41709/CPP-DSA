// Leetcode 1865
// Good Question
#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;
class FindSumPairs {
public:
    vector<int> v1;
    vector<int> v2;
    unordered_map<int, int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for(int i = 0;i < v2.size(); i++){
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        if(index >= v2.size()){
            mp[val]++;
            v2.push_back(val);
        }
        else{
            // like, {4,3} and val = 5 will become {4,2}and {9,1}
            mp[v2[index]] --; // kyuki ab val change ho jayegi toh map mei value change krni hoi 
            v2[index] += val;
            mp[v2[index]] ++;
        }
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i = 0;i<v1.size();i++){
            if(mp.find(tot - v1[i]) != mp.end()){
                cnt += mp[tot - v1[i]];
            }
        }
        return cnt;
    }
};
int main(){
    
    return 0;
}