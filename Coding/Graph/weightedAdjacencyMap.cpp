#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<unordered_map<int, int>> graph;
int v;  // number of vertices
void addEdge(int src, int dest, int weight,  bool bi_dir = true){
    graph[src][dest] = weight;
    if(bi_dir){
        graph[dest][src] = weight;
    }
}
void display(){
    for(int i = 0; i<v; i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")"<<", ";
        }
        cout<<"NULL"<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v, unordered_map<int, int>());
    cout<<"For Undirected Graph : Enter number of edges : ";
    int e; // number of edges
    cin>>e;
    while(e --){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        addEdge(src, dest, weight); // bidirectional
    }
    display();

    graph.clear();
    graph.resize(v, unordered_map<int, int>());
    cout<<"For Directed Graph : Enter number of edges : ";
    int e1; // number of edges
    cin>>e1;
    while(e1 --){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        addEdge(src, dest, weight, false); // bidirectional
    }
    display();
    return 0;
}

