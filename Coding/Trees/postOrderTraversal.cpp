// Leetcode - 145
// Left Right Root
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
    helper(v,root->left);
    helper(v,root->right);
    v.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
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
    v = postorderTraversal(a);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}