// TC = O(V + E)
// SC = O(V)
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
0
0 1 4 3 5 6 2 
0 1 3 2 1 2 3 -> distance of vertex 0 1 2 3 4 5 6 from src that is 0
*/
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
#include<climits>
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
void bfs(int src, int vertices, vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(vertices, INT_MAX);
    dist[src] = 0;
    q.push(src);
    visited.insert(src);
    while(! q.empty()){
        int curr = q.front();
        cout<<q.front()<<" ";
        q.pop();
        for(auto neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout<<endl;
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
    int src;
    cin>>src;
    vector<int> dist;
    bfs(src, v,  dist);
    for(int i = 0; i<v; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}