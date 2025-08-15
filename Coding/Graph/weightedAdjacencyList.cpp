/*
Output:
7
For Undirected Graph : Enter number of edges : 7
0 2 2
0 1 1
1 5 3
5 2 2
3 2 6
6 3 2
6 4 9
0->(2,2), (1,1), NULL
1->(0,1), (5,3), NULL
2->(0,2), (5,2), (3,6), NULL
3->(2,6), (6,2), NULL
4->(6,9), NULL
5->(1,3), (2,2), NULL
6->(3,2), (4,9), NULL
For Directed Graph : Enter number of edges : 7
0 2 2
0 1 1
1 5 3
5 2 2
3 2 6
6 3 2
6 4 9
0->(2,2), (1,1), NULL
1->(5,3), NULL
2->NULL
3->(2,6), NULL
4->NULL
5->(2,2), NULL
6->(3,2), (4,9), NULL
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<pair<int, int>>> graph;
int v;  // number of vertices
void addEdge(int src, int dest, int weight,  bool bi_dir = true){
    graph[src].push_back({dest, weight});
    if(bi_dir){
        graph[dest].push_back({src, weight});
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
    graph.resize(v, list<pair<int, int>>());
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
    graph.resize(v, list<pair<int, int>>());
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

