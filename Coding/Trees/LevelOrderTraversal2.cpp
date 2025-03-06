// More Optimized by only for left to right.
// Leetcode 102
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
int level(TreeNode* root){
    if(root == NULL) return 0;
    return (1 + max(level(root->left) , level(root->right)));
}
void LevelFill(TreeNode* root, vector<vector<int>>& ans, int levell){
    if(root == NULL) return;
    ans[levell].push_back(root -> val); // Like at 2 index we have 2nd level stored.
    LevelFill(root -> left, ans, levell+1);
    LevelFill(root -> right, ans, levell+1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    int n = level(root);
    for(int i = 0;i<n;i++){
        vector<int> vec;  // create empty vectors and push it on ans.
        ans.push_back(vec);
    }
    LevelFill(root,ans,0);
    return ans;
}
int main(){
    return 0;
}