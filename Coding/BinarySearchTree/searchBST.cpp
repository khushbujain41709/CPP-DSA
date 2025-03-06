// Leetcode 700
// Best case time complexity - O(log n) in case of balanced trees.
// Worst case time complexity - O(n) in case of skewed trees.
// Average case time complexity - O(height).
// Space complexity is same as time complexity.
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
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return NULL;
    if(root -> val == val) return root;
    if((root -> val) > val){
        return searchBST(root -> left , val);
    }
    else{
        return searchBST(root -> right , val);
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