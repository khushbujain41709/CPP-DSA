// Leetcode 103
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
void NthLevel(TreeNode* root, vector<int>& vec, int level , int curr){
    if(root == NULL) return;
    if(level == curr){
        vec.push_back(root->val);
        return;
    }
    NthLevel(root -> left, vec, level , curr+1);
    NthLevel(root -> right, vec, level , curr+1);
    }
void NthLevelRev(TreeNode* root, vector<int>& vec, int level , int curr){
    if(root == NULL) return;
    if(level == curr){
        vec.push_back(root->val);
        return;
    }
    NthLevelRev(root -> right, vec, level , curr+1);
    NthLevelRev(root -> left, vec, level , curr+1);
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> vec;
    int n = level(root);
    for(int i = 0;i<n;i++){
        if(i % 2 == 1){
            NthLevelRev(root,vec,i,0);
        }
        else NthLevel(root, vec, i,0);
        ans.push_back(vec);
        vec.clear();
    }
    return ans;
}
int main(){
    return 0;
}