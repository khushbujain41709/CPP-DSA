// Leetcode - 238
#include<iostream>
#include<vector>
using namespace std;
// WITH DIVISION
vector<int> productExceptSelf1(vector<int>& nums){
    int n = nums.size();
    int noz = 0; // number of zeroes
    int product = 1;
    int product2 = 1;
    for(int i = 0;i<n;i++){
        if(nums[i] == 0) noz++;
        if(nums[i] != 0)product2 *= nums[i]; // without zero product
        product *= nums[i]; // with zero product
    }
    if(noz > 1) product2 = 0;
    for(int i = 0;i<n;i++){
        if(nums[i] == 0) nums[i] = product2;
        nums[i] = product/nums[i];
    }  
    return nums;
}
// WITHOUT DIVISION
// {1 2 3 4}
// make prefix product series excluding itself {1(1) , 1(1) , 2(1*2) , 6(1*2*3)} = {1 1 2 6}
// make suffix product series excluding itself {24 12 4 1(4 k baad k sare element ka product)}
vector<int> productExceptSelf2(vector<int>& nums){
    int n = nums.size();
    vector<int> pre(n);
    vector<int> suf(n);
    vector<int> ans(n);
    // prefix product array
    pre[0] = 1;
    int product = nums[0];
    for(int i = 1;i<n;i++){
        pre[i] = product;
        product *= nums[i];
    }
    // suffix product array
    product =  nums[n-1];
    suf[n-1] = 1;
    for(int i = n-2;i>=0;i--){
        suf[i] = product; 
        product *= nums[i];
    }
    // answer product array
    for(int i = 0;i<n;i++){
        ans[i] = pre[i]*suf[i];
    }
    return ans;
}
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n);
    // prefix product array
    pre[0] = 1;
    int product = nums[0];
    for(int i = 1;i<n;i++){
        pre[i] = product;
        product *= nums[i];
    } 
    product =  nums[n-1]; // pre = [1,1,2,6] and product = 4
    for(int i = n-2;i>=0;i--){
        pre[i] *= product;  // pre = [8,6] // pre = [12,8,6] // pre = [24,12,8,6]
        product *= nums[i]; // product = 4*3 // product = 12*2 // product = 24*1
    }
    return pre;
}
int main(){
    
    return 0;
}