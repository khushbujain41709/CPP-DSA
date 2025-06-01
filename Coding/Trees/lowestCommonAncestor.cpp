// Leetcode - 236
// if p lies in LST and q lies in RST then LCA is root.
// if q lies in LST and p lies in RST then LCA is root.
#include<iostream>
#include<vector>
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
bool isExists(TreeNode* root ,TreeNode* target){
    if(root == NULL) return false;
    if(root == target) return true;
    return (isExists(root->left , target) || isExists(root->right , target));
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    else if(isExists(root -> left, p) && isExists(root -> right,q)) return root;
    else if(isExists(root -> left, q) && isExists(root -> right,p)) return root;
    else if(isExists(root -> left, p) && isExists(root -> left,q)) return lowestCommonAncestor(root->left,p,q);
    else return lowestCommonAncestor(root->right,p,q);
}
int main(){
    return 0;
}