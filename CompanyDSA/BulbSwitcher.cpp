// Leetcode 319
#include<iostream>
#include<math.h>
using namespace std;
bool isPerfectSquares(int z){
    int root = sqrt(z);  // sqrt has O(1) time complexity
    // z = 20 then root = 4 if z = 16 then also root = 4 so check ..
    if(root * root == z) return true;
    else return false; 
}
// if perfect square then it is on
int bulbSwitch(int n) {
    int count = 0;
    for(int i = 1;i<=n;i++){
        if(isPerfectSquares(i)) count ++;
    }
    return count;
}
int main(){
    
    return 0;
}