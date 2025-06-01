// 2+6*4/8-3
// 2+64*/8-3
// 2+*648/-3 , now + and - have same precedence so go left to right
// 2/*648+-3
// 2/*648+3-
#include<iostream>
#include<stack>
using namespace std;
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
string solve(char opp , string val1, string val2){
    string s = "";
    s += val1;
    s += val2;
    s.push_back(opp); // s += opp gives error
    return s;
}
int main(){
    stack<string> val; 
    stack<char> op;
    string s = "(7+9)*4/8-3";
    for(int i = 0;i<s.size();i++){
        if(s[i] >= 48 && s[i] <= 57){ // it's a digit
            val.push(to_string(s[i]-48)); 
        }
        else{
            if(op.empty()){
                op.push(s[i]);
            }
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){
                while(op.size() > 0 && op.top() != '('){
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    char opp = op.top();
                    op.pop();
                    string ans = solve(opp, val1, val2);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(op.top()) < prio(s[i])){
                op.push(s[i]);
            }
            else{
                while(op.size() > 0 && prio(op.top()) >= prio(s[i])){
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    char opp = op.top();
                    op.pop();
                    string ans = solve(opp, val1, val2);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size() > 0){
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        char opp = op.top();
        op.pop();
        string ans = solve(opp, val1, val2);
        val.push(ans);
    }
    cout<<val.top()<<endl;
    return 0;
}