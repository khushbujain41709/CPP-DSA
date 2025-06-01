// Leetcode - 1038
#include<bits/stdc++.h>
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
void inorderRev(TreeNode* root, int& sum){
    if(root == NULL) return;
    inorderRev(root->right,sum);
    root->val += sum;
    sum = root->val;
    inorderRev(root->left, sum);
}
TreeNode* bstToGst(TreeNode* root) {
    if(root == NULL) return root;
    int sum = 0;
    inorderRev(root, sum);
    return root;
}
int main(){

}