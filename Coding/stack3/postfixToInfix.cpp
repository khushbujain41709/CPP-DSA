#include<iostream>
#include<stack>
using namespace std;
string solve(string val1, string val2, char op){
    string s = "";
    s += val1;
    s.push_back(op);
    s += val2;
    return s;
}
int main(){
    string s = "79+4*8/3-";
    stack<string> val;
    for(int i = 0;i<s.size();i++){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(to_string(s[i]-48));
        }
        else{
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            char op = s[i];
            string ans = solve(val1, val2 , op);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    return 0;
}