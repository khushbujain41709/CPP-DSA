// Leetcode 1814
// Hint : nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) This is given in question.
// Now transform equation as : nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])
// Transform each nums[i] into (nums[i] - rev(nums[i])). Then, count the number of (i, j) pairs that have equal values.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// method 1
long long nc2(long long n){
    // calculation nc2 = n(n-1)/2;
    return (n*(n-1)/2);
}
int reverse(int n){
    int r = 0;
    while(n > 0){
        r *= 10;
        r += (n % 10);
        n /= 10;
    }
    return r;
}
int countNicePairs(vector<int>& nums){
    int n = nums.size();
    int MOD = 1e9 + 7; // can be written as int MOD =  1000000000 + 7
    // Transform the array
    for(int i = 0;i<n;i++){
        nums[i] = nums[i] - reverse(nums[i]);
    }
    unordered_map<int, int> m;
    for(int i = 0;i<n;i++){
        m[nums[i]]++;
    }
    long long count = 0;
    for(auto x : m){
        long long freq = x.second;
        count += nc2(freq);
    }
    return count % MOD;
}

// method 2 - more efficient 
int countNicePairs(vector<int>& nums){
    int n = nums.size();
    int MOD = 1e9 + 7; // can be written as int MOD =  1000000000 + 7
    // Transform the array
    for(int i = 0;i<n;i++){
        nums[i] = nums[i] - reverse(nums[i]);
    }
    unordered_map<int, int> m;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(m.find(nums[i]) != m.end()){
            count = count % MOD;
            count += m[nums[i]];  // add initial frequency to count
        }
        m[nums[i]]++; // then increment frequency
    }
    return count % MOD;
}
int main(){
    
    return 0;
}