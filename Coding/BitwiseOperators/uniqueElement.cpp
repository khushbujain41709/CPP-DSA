// // Leetcode - 136
// x^0 = x
// x^x = 0
// xor is a commutative and associative property
// In an array, Every element occurs twice times excpet one element . Return that element.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {3,1,2,4,6,2,1,4,3};
    int res = 0;
    for(int i = 0 ;i< v.size() ; i++){
        res = res ^ v[i];
    }
    cout<<res<<endl;
    return 0;
}