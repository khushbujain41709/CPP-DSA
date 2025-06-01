// Leetcode 106
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
TreeNode* build(vector<int>& inorder, int inlo, int inhi, vector<int>& postorder , int polo, int pohi){
    if(polo > pohi || inlo > inhi) return NULL;
    TreeNode* root = new TreeNode(postorder[pohi]);
    if(polo == pohi) return root;
    int i = inlo;
    while(inlo <= inhi){
        if(inorder[i] == postorder[pohi]) break;
        i++;
    }
    int leftCount = i - inlo;
    int rightCount = inhi - i;
    root -> left = build(inorder , inlo , i-1 , postorder, polo , polo + leftCount - 1);
    root -> right = build(inorder , i+1 , inhi , postorder, pohi - rightCount, pohi -1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size();
    TreeNode* root = build(inorder , 0 , n-1 , postorder, 0 , n-1);
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