/*
7
8
0 1
0 3
1 3
1 4
3 4
2 6
2 5
6 5
0->1 3 
1->0 3 4
2->6 5
3->0 1 4
4->1 3
5->2 6
6->2 5
2
*/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph;
int vertices;
void addEdge(int src, int dest, bool di_dir = true){
    graph[src].push_back(dest);
    if(di_dir){
        graph[dest].push_back(src);
    }
}
void dfs(int node, unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbour: graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour, visited);
        }
    }
}
int connectedComponents(){
    unordered_set<int> visited;
    int count = 0;
    for(int i = 0; i<vertices; i++){
        if(visited.count(i) == 0){
            count++;
            dfs(i, visited);
        }
    }
    return count;
}
void display(){
    for(int i = 0; i< vertices; i++){
        cout<<i<<"->";
        for(auto x: graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cin>>vertices;
    graph.resize(vertices, list<int>());
    int edges;
    cin>>edges;
    while(edges --){
        int src, dest;
        cin>>src>>dest;
        addEdge(src, dest);
    }
    display();
    cout<<connectedComponents();
}