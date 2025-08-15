/*
7
8
0 1
0 4
1 3
4 3
1 5
5 6
6 2
5 2
0->1, 4, NULL
1->0, 3, 5, NULL
2->6, 5, NULL
3->1, 4, NULL
4->0, 3, NULL
5->1, 6, 2, NULL
6->5, 2, NULL
0 6
0 1 5 6 
0 1 5 2 6
0 4 3 1 5 6
0 4 3 1 5 2 6
*/
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> allPathVector;
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
void dfs(int curr, int dest, vector<int>& path){
    if(curr == dest){
        path.push_back(curr);
        allPathVector.push_back(path);
        path.pop_back();  // so that we can explore other path also from parent node
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour, dest, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
bool allPath(int src, int dest){
    vector<int> v;
    dfs(src, dest, v);
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
    allPath(x, y);
    for(int i = 0; i< allPathVector.size(); i++){
        for(int j = 0; j< allPathVector[i].size(); j++){
            cout<<allPathVector[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}