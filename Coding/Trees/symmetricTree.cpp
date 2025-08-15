// Leetcode 101
#include<iostream>
#include<climits>
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
bool isMirror(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;
    return (root1->val == root2-> val && isMirror(root1->left, root2 ->right) && isMirror(root1->right, root2 ->left));
}
bool isSymmetric(TreeNode* root) {
    return (isMirror(root->left , root -> right));
}
int main(){
    return 0;
}