// Leetcode 701
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
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL){
        return new TreeNode(val);
    }
    else if((root-> val) > val){
        if(root-> left == NULL){
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
        }
        else insertIntoBST(root -> left , val);
    }
    else{
        if(root-> right == NULL){
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
        }
        else insertIntoBST(root -> right , val);
    }
    return root;
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