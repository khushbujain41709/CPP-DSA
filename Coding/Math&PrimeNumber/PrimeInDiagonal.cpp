#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isPrime(int n){ 
    if(n == 1){
        return false;
    }
    for(int i = 2;i<=sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;     
}
int diagonalPrime(vector<vector<int>>& nums){ // O(n^(3/2)) 
    int rows = nums.size();
    // int cols = nums[0].size();
    int maxx = 0;
    for(int i = 0;i<rows;i++){
        if(isPrime(nums[i][i])){
            maxx = max(maxx,nums[i][i]);
        }
        if(isPrime(nums[i][rows-i-1])){
            maxx = max(maxx, nums[i][rows-i-1]);
        }
    }
    return maxx;
}
int main(){
    
    return 0;
}