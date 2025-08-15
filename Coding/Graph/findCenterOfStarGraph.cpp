// Leetcode 1791
#include<iostream>
#include<vector>
using namespace std;
// Since my graph is a star graph so instead of checking all edges which takes O(V+E) times, pick any two edges and find intersecting node.
// In constraints, it is given that there always exist atleast two edges.
int findCenter(vector<vector<int>>& edges){
    int a = edges[0][0];
    int b = edges[0][1];
    int c = edges[1][0];
    int d = edges[1][1];
    if(a == c || b == c){
        return c;
    }
    else{
        return d;
    }
}
int main(){
    
    return 0;
}