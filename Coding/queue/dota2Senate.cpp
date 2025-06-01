// Leetcode 649
#include<iostream>
#include<queue>
using namespace std;
string predictPartyVictory(string senate) {
    queue<int> q, r , d;
    int n = senate.size();
    for(int i = 0;i<n;i++){
        q.push(i);
        if(senate[i] == 'R'){
            r.push(i);
        }
        else if(senate[i] == 'D'){
            d.push(i);
        }
    }
    while(q.size() > 1){
        if(senate[q.front()] == 'R'){
            if(d.size() != 0){
                int x = d.front();
                d.pop();
                senate[x] = 'X';
                q.push(q.front());
                q.pop();
                r.push(r.front());
                r.pop();
            }
            else{
                return "Radiant";
            }
        }
        else if(senate[q.front()] == 'D'){
            if(r.size() != 0){
                int x = r.front();
                r.pop();
                senate[x] = 'X';
                q.push(q.front());
                q.pop();
                d.push(d.front());
                d.pop();
            }
            else{
                return "Dire";
            }
        }
        else{ // if char is X
            q.pop();
        }
    }
    if(senate[q.front()] == 'R'){
        return "Radiant";
    }
    else if(senate[q.front()] == 'D'){
        return "Dire";
    }
    return ""; // to avoid compiler error
}
int main(){
    
    return 0;
}