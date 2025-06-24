#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string remove(string num,int k){
    stack<int> st;
    int n = num.size();
    for(int i = 0;i<n;i++){  
        while(!st.empty() && st.top() > num[i] && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]); // st = [1 4 5 6 7 8 9]
    }
    while(k > 0 && !st.empty()){
        st.pop();
        k--;
    } // st = [1 4 5 6]
    string result = "";
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    reverse(result.begin() , result.end());
    // removing leading zeroes
    while(result[0] == 0){
        result.erase(result.begin());
    }
    return result;
}
int main(){

}