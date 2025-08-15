// TC = O(V + E)
// SC = O(V) in worst case
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
void addEdge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(int v){
    for(int i = 0; i<v; i++){
        cout<<i<<"->";
        for(auto ele: graph[i]){
            cout<<ele<<", ";
        }
        cout<<"NULL"<<endl;
    }
}
bool dfs(int curr, int dest){
    if(curr == dest) return true;  // imp
    visited.insert(curr);
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour, dest);
            if(result) return true;
        }
    }
    return false;
}
bool anyPath(int src, int dest){
    return dfs(src, dest);
}
int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    visited.clear();
    while(e--){
        int src, dest;
        cin>>src>>dest;
        addEdge(src, dest);
    }
    display(v);
    int x, y;
    cin>>x>>y; // To find is there any path between x and y
    cout<<anyPath(x, y);
    return 0;
}