// Leetcode 242
// In this question, we if use sorting then TC = O(nlogn) but if we use hashmaps the TC = O(n)
#include<iostream>
#include<unordered_map>
using namespace std;
// method 1 : Here we make 2 hashmaps containing character and its frequency. This is also known as frequency array 
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for(int i = 0;i<s.length();i++){
        mp1[s[i]]++;
    }
    for(int i = 0;i<t.length();i++){
        mp2[t[i]]++;
    }
    for(auto x : mp1){
        char ch1 = x.first;
        int freq1 = x.second;
        if(mp2.find(ch1) != mp2.end()){
            int freq2 = mp2[ch1];
            if(freq1 != freq2){
                return false;
            }
        }
        else return false;
    }
    return true;
}
// method 2
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, int> mp1;
    for(int i = 0;i<s.length();i++){
        mp1[s[i]]++;
    }
    for(int i = 0;i<t.length();i++){
        char ch = t[i];
        if(mp1.find(ch) != mp1.end()){
            mp1[ch]--;
            if(mp1[ch] == 0) mp1.erase(ch);
        }
        else{
            return false;
        }
    }
    if(mp1.size() > 0) return false;
    return true;
}
int main(){
    
    return 0;
}