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
    string s = "79+4*8/3-";
    stack<int> val;
    for(int i = 0;i<s.size();i++){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(s[i]-48);
        }
        else{
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            char op = s[i];
            int ans = solve(val1, val2 , op);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    return 0;
}