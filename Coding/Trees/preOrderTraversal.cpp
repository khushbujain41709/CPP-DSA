// Leetcode - 144
// TC = O(n) where n is number of nodes.
// SC = O(no. of levels of tree + 1). See call stack of recursion. 1 is added for NULL.
// SC = O(no. of levels of tree + 1) = O(height of tree + 2) = O(height of tree) nearly.But in best case it is usually O(logn) and in worst/average case it is O(n)
// In balanced trees, 
// Root Left Right
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
void helper(vector<int>& v , TreeNode* root){
    if(root == NULL){
        return ;
    }
    v.push_back(root->val);
    helper(v,root->left);
    helper(v,root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    helper(v,root);
    return v;
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

    vector<int> v;
    v = preorderTraversal(a);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}