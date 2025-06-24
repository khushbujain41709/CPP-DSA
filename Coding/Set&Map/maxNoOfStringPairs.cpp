// Leetcode 2744
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// method 1
int maximumNumberOfStringPairs(vector<string>& words) {
    int n = words.size();
    unordered_set<string> s;
    for(int i = 0; i < n ; i++){
        s.insert(words[i]);
    }
    int count = 0;
    for(int i = 0; i < n ; i++){
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        if(words[i] == rev) continue;
        if(s.find(rev) != s.end()){
            s.erase(words[i]);
            count++;
        }
    }
    return count;
}
// method 2
int maximumNumberOfStringPairs(vector<string>& words) {
    int n = words.size();
    unordered_set<string> s;
    int count = 0;
    for(int i = 0; i < n ; i++){
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        if(s.find(rev) == s.end()){
            s.insert(words[i]);
        }
        else{
            count ++;
        }
    }
    return count;
}
int main(){
    
    return 0;
}