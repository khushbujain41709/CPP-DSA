// Leetcode 112
// Leetcode 113
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
bool hasPathSum(TreeNode* root, int targetSum){
    if(root == NULL) return false;
    if(root->left == NULL && root-> right == NULL){
        if(targetSum == root-> val){
            return true;
        }
    } 
    return (hasPathSum(root->left , targetSum - (root -> val)) || hasPathSum(root -> right , targetSum - (root-> val)));
    return true;
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    return 0;
}