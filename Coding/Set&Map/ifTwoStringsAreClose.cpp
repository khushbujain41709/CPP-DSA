// Leetcode 1657
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// TC = O(n) and SC = O(n)
bool closeStrings(string word1, string word2) {
    if(word1.length() != word2.length()) return false;
    // first match, if all characters are same in both the strings
    // then match, the frequency of the characters in both the strings
    // like word1 = "cabbba", word2 = "abbccc"
    // so in word1 characters are : c, a, b and in word2 characters are : a, b, c
    // and in word1 : a-2, b-3, c-1 and in word2 : a-1, b-2, c-3
    int n1 = word1.length();
    int n2 = word2.length();
    // fill both maps - character as key and frequency as value
    unordered_map<char,int> m1, m2;
    for(int i = 0; i< n1;i++){
        m1[word1[i]]++;
    }
    for(int i = 0; i< n2;i++){
        m2[word2[i]]++;
    }
    // check if all characters are present or not
    for(auto x : m1){
        char ch = x.first;
        if(m2.find(ch) == m2.end()) return false;
    }
    // fill both maps - frequency as key and their frequency as value
    unordered_map<int,int> j1, j2;
    for(auto x : m1){
        j1[x.second]++;
    }
    for(auto x : m2){
        j2[x.second]++;
    }
    // then match the frequencies 
    for(auto x : j1){
        int freq = x.second;
        int ele = x.first;
        if(j2.find(ele) == j2.end()){
            return false;
        }
        else{
            if(j2[ele] != freq){
                return false;
            }
        }
    }
    return true;
}
int main(){
    
    return 0;
}