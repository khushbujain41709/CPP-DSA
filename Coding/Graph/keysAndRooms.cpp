// Leetcode 841
#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> visited;
    queue<int> q;
    visited.insert(0);
    q.push(0);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour : rooms[curr]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    return visited.size() == rooms.size();
}
int main(){
    
    return 0;
}