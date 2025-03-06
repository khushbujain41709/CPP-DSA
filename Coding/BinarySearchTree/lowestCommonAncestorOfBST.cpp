// Leetcode - 235
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL) return root;
    if(root -> val == p -> val || root -> val == q -> val) return root;
    else if(root -> val > p -> val && root -> val < q -> val) return root;
    else if(root -> val > q -> val && root -> val < p -> val) return root;
    else if(root -> val > p -> val && root -> val > q -> val){
        return lowestCommonAncestor(root->left , p , q);
    }
    else{
        return lowestCommonAncestor(root->right , p , q);
    }
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