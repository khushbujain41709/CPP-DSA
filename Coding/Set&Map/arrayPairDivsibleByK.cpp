// Leetcode 1497
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Step 1 - Do arr[i] % k for every element of array
// Now notice, every pair will have sum k or 0
// -a % b = -[a % b]
// a % -b = a % b
bool canArrange(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int,int> m;
    for(int i = 0;i<n;i++){ // frequency in value of map
        arr[i] = ((arr[i] % k) + k) % k ;  // for negative and positive numbers both
        m[arr[i]]++;
    }
    if(m.find(0) != m.end()){ // agar zero milta hai toh uski frequency even honi chahiye
        if(m[0] % 2 != 0 ) return false;
        m.erase(0);  // then zero ko hatha do map se
    }
    for(auto x : m){
        int ele = x.first;
        int rem = k - ele;
        if(m.find(rem) == m.end()) return false;
        if(m[ele] != m[rem]) return false;  // dono ki frequency same honi chahiye
    }
    return true;
}
int main(){
    
    return 0;
}