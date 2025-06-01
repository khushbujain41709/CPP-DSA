// Leetcode - 257
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
 void helper(TreeNode* root, string s, vector<string>& ans){
    if(root == NULL) return; // do nothing
    string str = to_string(root->val);
    if(root -> left == NULL && root->right == NULL){
        s += str;
        ans.push_back(s);
        return;
    } 
    helper(root->left , s+str+"->" , ans);
    helper(root->right , s+str+"->" , ans);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    helper(root,"",ans);
    return ans;
}
int main(){
    return 0;
}