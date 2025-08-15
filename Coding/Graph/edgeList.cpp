#include<iostream>
#include<vector>
using namespace std;

// Edge List Implementation - Time Consuming but Clean
class Node{
    int val;
    Node(int data){
        val = data;
    }
};
class Edge{
    Node source;
    Node destination;
    bool direction;  // If 1 then unidirectional otherwise bidirectional
    float weight;
};
class Graph{
    vector<Edge> edges;
    vector<Node> vertices;
};

int main(){
    
    return 0;
}