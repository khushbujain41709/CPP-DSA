// Leetcode 713
// j - i gives number of subarray starting with i fulfilling the condition  
#include<iostream>
#include<vector>
using namespace std; 
// method 1
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if( k <= 1) return 0;
    int n = nums.size() ;
    int count = 0;
    int i = 0;
    int j = 0;
    int product = 1;
    while(j < n){
        if(product < k){
            product *= nums[j];
        }
        while(product >= k){ // as strictly less than is given in question
            count += j - i;
            product /= nums[i];
            i++;
        }
        j++;
    }
    while(i < n){ 
        count += j - i;
        product /= nums[i];
        i++;
    }
    return count;
} 
// method 2
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int count = 0;
    int product = 1;
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        product *= nums[j];
        while (product >= k) {
            product /= nums[i];
            ++i;
        }
        count += j - i + 1;
    }
    return count;
}
int main(){
    
    return 0;
}