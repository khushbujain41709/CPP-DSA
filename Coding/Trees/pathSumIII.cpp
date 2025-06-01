// Leetcode 437
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
void helper(TreeNode* root, vector<vector<int>>& ans, int target , vector<int> vec){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL && target == root->val){
        vec.push_back(root->val);
        ans.push_back(vec);
    }
    vec.push_back(root->val);
    if(root ->left != NULL){
        helper(root->left, ans, target - (root->val), vec);           
    }
    if(root ->right != NULL){
        helper(root->right,ans, target - (root->val) ,vec);
    }
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    helper(root, ans, targetSum ,{});
    return ans;
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