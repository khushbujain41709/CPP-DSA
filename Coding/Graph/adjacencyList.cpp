// Adjacency List Implementation - Recommended
// In this approach, we store graph as an array of linked list.
/*
Output:
7
For Undirected Graph : Enter number of edges : 7
0 2
0 1
1 5
5 2
3 2
6 3
6 4
0->2,1,NULL
1->0,5,NULL
2->0,5,3,NULL
3->2,6,NULL
4->6,NULL
5->1,2,NULL
6->3,4,NULL
For Directed Graph : Enter number of edges : 7
0 2
0 1
1 5
5 2
3 2
6 3
6 4
0->2,1,NULL
1->5,NULL
2->NULL
3->2,NULL
4->NULL
5->2,NULL
6->3,4,NULL
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph;
int v;  // number of vertices
void addEdge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i = 0; i<v; i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<",";
        }
        cout<<"NULL"<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v, list<int>());
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
    graph.resize(v, list<int>());
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

