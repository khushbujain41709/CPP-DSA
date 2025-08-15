#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<unordered_set<int>> graph;
int v;  // number of vertices
void addEdge(int src, int dest,  bool bi_dir = true){
    graph[src].insert(dest);
    if(bi_dir){
        graph[dest].insert(src);
    }
}
void display(){
    for(int i = 0; i<v; i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<", ";
        }
        cout<<"NULL"<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v, unordered_set<int>());
    cout<<"For Undirected Graph : Enter number of edges : ";
    int e; // number of edges
    cin>>e;
    while(e --){
        int src, dest;
        cin>>src>>dest;
        addEdge(src, dest); // bidirectional
    }
    display();

    graph.clear();
    graph.resize(v, unordered_set<int>());
    cout<<"For Directed Graph : Enter number of edges : ";
    int e1; // number of edges
    cin>>e1;
    while(e1 --){
        int src, dest;
        cin>>src>>dest;
        addEdge(src, dest, false); // bidirectional
    }
    display();
    return 0;
}

