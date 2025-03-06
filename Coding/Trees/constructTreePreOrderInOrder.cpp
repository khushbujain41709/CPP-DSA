// Leetcode 105
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
TreeNode* build(vector<int>& preorder, int prelo, int prehi, vector<int>& inorder, int inlo , int inhi){
    if(prelo > prehi || inlo > inhi) return NULL;
    TreeNode* root = new TreeNode(preorder[prelo]); 
    if(prelo == prehi) return root;
    int i = inlo;
    while(inlo <= inhi){
        if(inorder[i] == preorder[prelo]) break; // imp line
        i++;
    }
    int leftCount = i -inlo;
    int rightCount = inhi - i;
    root ->left = build(preorder, prelo + 1 , prelo + leftCount , inorder , inlo , i-1);
    root ->right = build(preorder, prelo + leftCount + 1 , prehi , inorder , i+1 , inhi);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    TreeNode* root = build(preorder, 0 , n-1 , inorder , 0 , n-1);
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