// Leetcode - 543
/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. "This path may or may not pass through the root."
The length of a path between two nodes is represented by the number of edges between them.
*/
// Hint : Visit each node
#include<iostream>
#include<climits>
using namespace std;
class TreeNode{
    public :
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int maxDia = 0;  // global variable but interviewers don't like it.
int level(TreeNode* root){
    if(root == NULL) return 0;
    return (1 + max(level(root->left) , level(root->right)));
}
int diameterOfBinaryTree(TreeNode* root){
    if(root == NULL) return 0;
    int dia = level(root->left) + level(root->right);    
    maxDia = max(maxDia , dia);
    diameterOfBinaryTree(root->left);
    diameterOfBinaryTree(root->right);
    return maxDia;
}
// Instead use helper function and pass maxDia by reference
void helper(TreeNode* root, int& maxDia){
    if(root == NULL) return;
    int dia = level(root->left) + level(root->right);    
    maxDia = max(maxDia , dia);
    helper(root->left,maxDia);
    helper(root->right,maxDia);
}
int diameterOfBinaryTree2(TreeNode* root){
    int maxDia = 0;
    helper(root,maxDia);
    return maxDia;
}
int main(){
    return 0;
}