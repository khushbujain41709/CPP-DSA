// Leetcode 133
// We maintain a vector of node pointer where we store address of newly formed node.
// If ith index has NULL then we can say that ith node has not been created yet otherwise it has been created.
#include<iostream>
#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
vector<Node*> nodeRegister;
void dfs(Node* actual, Node* clone){
    for(auto neighbour : actual->neighbors){  // traverse actual node neighbours
        if(not nodeRegister[neighbour-> val]){ // if node is not created
            // create the neighbour for the first time 
            Node* newNode = new Node(neighbour->val);
            nodeRegister[neighbour->val] = newNode;
            clone->neighbors.push_back(newNode);
            dfs(neighbour, newNode);
        }
        else{
            // if new node is already created
            clone->neighbors.push_back(nodeRegister[neighbour->val]);
        }
    }
}
Node* cloneGraph(Node* node){
    if(node == NULL) return NULL;
    nodeRegister.resize(110, NULL); // this array contains reference to the created nodes
    Node* clone = new Node(node-> val);
    nodeRegister[clone->val] = clone;  // Store address of ith node at ith index
    dfs(node, clone);
    return clone;
}
int main(){
    
    return 0;
}