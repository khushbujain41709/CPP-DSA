// Leetcode 733
// Problem is giving an intuition of recursion
// We don't need to construct actual graph of grid in 90 percent of grid based DFS BFS peoblems.
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>& image, int currRow,int currCol, int initialColor, int color){
    int m = image.size();
    int n = image[0].size();
    if(currRow < 0 || currCol < 0 || currRow >= m || currCol >= n ){
        return;
    }
    // If cell you landed is not of initial color
    if(image[currRow][currCol] != initialColor) return; // imp
    // Otherwise chnage color to color and check all four directions
    image[currRow][currCol] = color;
    dfs(image, currRow+1, currCol, initialColor, color); // down
    dfs(image, currRow-1, currCol, initialColor, color); // up
    dfs(image, currRow, currCol+1, initialColor, color); // right
    dfs(image, currRow, currCol-1, initialColor, color); // left
    return;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) return image;
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}
int main(){
}