// Leetcode 110
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public :
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int height(TreeNode* root){
    if(root == NULL) return 0;
    return(1 + max(height(root->left) , height(root ->right)));
}
bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int leftH = height(root -> left);
    int rightH = height(root -> right);
    if( abs(leftH - rightH) >= 2) return false;
    return (isBalanced(root-> left) && isBalanced(root -> right));
}
int main(){
    return 0;
}