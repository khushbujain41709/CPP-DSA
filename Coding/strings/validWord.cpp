// Leetcode 3136
#include<iostream>
using namespace std;
bool isValid(string s) {
    // ascii code of dollar $ is 36
    // ascii code of hash # is 35
    // ascii code of at sign @ is 64
    // ascii code of capital letters is 65 to 90
    // ascii code of digits from 0 to 9 is 48 to 71
    // ascii code of small letters is 97 to 122
    int n = s.size();
    int countVowel = 0;
    int countCons = 0;
    if(n < 3)return false;
    for(int i = 0 ; i<n; i++){
        // see constraints
        if((int)s[i] == 36 || (int)s[i] == 35 || (int)s[i] == 64) return false;
        if(isalpha(s[i])){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O'|| s[i] == 'U'){
            countVowel++;
            }
            else countCons++;
        }
    }
    if(countVowel >= 1 && countCons >= 1) return true;
    else return false;
}
int main(){
    
    return 0;
}