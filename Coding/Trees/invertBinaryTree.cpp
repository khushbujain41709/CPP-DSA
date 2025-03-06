// Leetcode - 226
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
TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
// method 2 - better one
void helper(TreeNode* root){
    if(root == NULL) return ;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
}
TreeNode* invertTree(TreeNode* root) {
    helper(root);
    return root;
}
int main(){
    return 0;
}