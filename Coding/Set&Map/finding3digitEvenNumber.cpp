// Leetcode 2094
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> findEvenNumbers(vector<int>& digits){
    unordered_map<int, int> m;
    vector<int> ans;
    int n = digits.size();
    for(auto ele : digits){
        m[ele]++;
    }
    for(int i = 100 ; i<= 999; i += 2){ // even jumps for even numbers
        int x = i;
        int a = x % 10; // ones place digit
        x /= 10;
        int b = x % 10; // tens place digit
        x /= 10;
        int c = x;   // hundreds place digit  // here we can also write int c = x % 10;
        if(m.find(a) != m.end()){  // set mei "a" hai
            m[a]--;
            if(m[a] == 0) m.erase(a);
            if(m.find(b) != m.end()){ // set mei "a"  and "b" dono hai
                m[b]--;
                if(m[b] == 0) m.erase(b); 
                if(m.find(c) != m.end()){ // set mei "a", "b" and "c" teeno hai
                    ans.push_back(i);
                }
                m[b]++;
            }
            m[a]++;
        }
        else{
            continue;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}