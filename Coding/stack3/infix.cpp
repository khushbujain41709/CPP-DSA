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
int prio(char op){
    if(op == '+'){
        return 1;
    }
    else if(op == '-'){
        return 1;
    }
    else if(op == '*'){
        return 2;
    }
    else {
        return 2;
    }
}
int main(){
    stack<int> val; 
    stack<char> op;
    string s = "(7+9)*4/8-3";
    for(int i = 0;i<s.size();i++){
        if(s[i] >= 48 && s[i] <= 57){ // it's a digit
            val.push(s[i]-48); // imp
        }
        else{
            if(op.empty()){
                op.push(s[i]);
            }
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){
                while(op.size() > 0 && op.top() != '('){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char opp = op.top();
                    op.pop();
                    int ans = solve(val1,val2, opp);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(op.top()) < prio(s[i])){
                op.push(s[i]);
            }
            else{
                while(op.size() > 0 && prio(op.top()) >= prio(s[i])){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char opp = op.top();
                    op.pop();
                    int ans = solve(val1,val2, opp);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size() > 0){
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        char opp = op.top();
        op.pop();
        int ans = solve(val1,val2, opp);
        val.push(ans);
    }
    cout<<val.top()<<endl;
    return 0;
}