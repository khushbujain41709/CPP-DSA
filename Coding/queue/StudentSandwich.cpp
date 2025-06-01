// Leetcode 1700
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int n = students.size();
    queue<int> q;
    for(int i = 0;i<n;i++){
        int x = students[i];
        q.push(x);
    }
    int count = 0;
    int i = 0; // to traverse in sandwiches array
    while(!q.empty() && count != q.size()){
        if(sandwiches[i] == q.front()){
            count = 0;
            i++;
            q.pop();
        }
        else{
            count ++;
            q.push(q.front());
            q.pop();
        }
    }
    return q.size();
}
int main(){
    return 0;
}