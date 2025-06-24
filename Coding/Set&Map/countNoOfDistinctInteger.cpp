// Leetcode 2442
// count number of distinct integer after reverse operations
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int reverse(int num){
    int r = 0;
    while(num > 0){
        r *= 10;
        r += (num % 10);
        num /= 10;
    }
    return r;
}
int countDistinctIntegers(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> s;
    for(int i = 0; i< n ;i++){
        int rev = reverse(nums[i]);
        s.insert(nums[i]);
        s.insert(rev);
    }
    return s.size();
}
int main(){
    
    return 0;
}