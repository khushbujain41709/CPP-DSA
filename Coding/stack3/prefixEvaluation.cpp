// traverse in reverse
// interchange val1 and val2 that is pop val1 first then val2.
#include<iostream>
#include<stack>
using namespace std;
int solve(int val1, int val2, char op){
    if(op == '+'){
        return val1+val2;
    }
    else if(op == '-'){
        return val1-val2;
    }
    else if(op == '*'){
        return val1*val2;
    }
    else {
        return val1/val2;
    }
}
int main(){
    string s = "-/*+79483";
    stack<int> val;
    for(int i = s.size()-1;i>=0;i--){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(s[i]-48);
        }
        else{
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            char op = s[i];
            int ans = solve(val1, val2 , op);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    return 0;
}